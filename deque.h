#ifndef __DEQUE__
#define __DEQUE__
#include <iostream>
#include <stdexcept>

namespace IAM_DS 
{
    template < typename value_type >
    class deque
    {
    public:
        // create an empty deque
        deque();

        // deque copy contructor
        deque(const deque&);

        // create a deque with default elements
        explicit deque(const size_t, const value_type&);

        // deque destructor
        ~deque();

        // deque assignment operator
        deque<value_type>& operator = (const deque<value_type>&);

        // adds element from back of container
        void push_back(const value_type&);

        // adds element from front of container
        void push_front(const value_type&);

        // pops element from back of conatiner
        void pop_back();

        // pops element from front of container
        void pop_front();

        // checks if conatiner is empty
        bool empty() const;

        // count of elements in container
        size_t size() const;

        // clears the container
        void clear();

        // return the referece to the element in deque at the given position
        value_type& operator[](size_t) const;

        // compares deques lexographically
        bool operator<(const deque&) const;
        bool operator>(const deque&) const;
        bool operator==(const deque&) const;
        bool operator!=(const deque&) const;
        bool operator<=(const deque&) const;
        bool operator>=(const deque&) const;

        // prints elements in deque in a row
        void print();



    private:
        size_t _array_count, _array_size;
        size_t _front_array, _end_array, _front_index, _end_index;
        value_type ** _container;

        void reallocate();
    };

    template < typename value_type >
    void deque<value_type>::reallocate() {
        size_t _previous_count = _end_array - _front_array + 1;
        for(size_t i = 0; i < _array_count; i++) {
            if (i > _end_array || i < _front_array) {
                delete[] _container[i];
            }
        }

        _array_count <<= _previous_count << 1 + (_previous_count & 1);
        value_type ** _ncontainer = new value_type*[_array_count];

        for(size_t i = (_previous_count + 1) / 2; i < (3 * _previous_count + 1) / 2; ++i) {
            _ncontainer[i] = _container[i - (_previous_count + 1) / 2];
        }

        delete[] _container;
        _container = _ncontainer;

        _front_array = (_previous_count + 1) / 2;
        _end_array = (3 * _previous_count + 1) / 2;
    }

    template < typename value_type >
    deque<value_type>::deque() :
        _front_array(1),
        _end_array(1),
        _array_count(2),
        _front_index(0),
        _end_index(0),
        _array_size(sizeof(value_type) > 256 ? 1 : 256 / sizeof(value_type))
    {
        _container = new value_type*[_array_count];
        _container[0] = nullptr;
        _container[1] = new value_type[_array_size];

    }

    template < typename value_type >
    deque<value_type>::deque(const deque<value_type>& other) :
        _front_array(other._front_array),
        _end_array(other._end_array),
        _front_index(other._front_index),
        _end_index(other._end_index),
        _array_count(other._array_count),
        _array_size(other._array_size)
    {
        _container = new value_type*[_array_count];

        for(size_t i = 0; i < _array_count; ++i) {
            if (i < _front_array || i > _end_array) {
                _container[i] = nullptr;
                continue;
            }

            _container[i] = new value_type[_array_size];
            for(size_t j = (i == _front_array ? _front_index : 0); j < (i == _end_array ? _end_index : _array_size); ++j) {
                _container[i][j] = other._container[i][j];
            }
        }
    }

    template < typename value_type >
    deque<value_type>::deque(const size_t count, const value_type& element) :
        _array_size(sizeof(value_type) > 256 ? 1 : 256 / sizeof(value_type))
    {
        _array_count = ((count - 1) / _array_size) + 3;
        _front_index = 0;
        _end_index = (count % _array_size);
        _front_array = 1;
        _end_array = _array_count - 2;
        _container = new value_type*[_array_count];

        for(size_t i = 0; i < _array_count; ++i) {
            if (i < _front_array || i > _end_array) {
                _container[i] = nullptr;
                continue;
            }

            _container[i] = new value_type[_array_size];
            for(size_t j = 0; j < (i == _end_array ? _end_index : _array_size); ++j)
                _container[i][j] = element;
        }
    }

    template < typename value_type >
    deque<value_type>::~deque()
    {
        for(size_t i = 0; i < _array_count; i++)
            delete[] _container[i];
        delete[] _container;
    }

    template < typename value_type >
    deque<value_type>& deque<value_type>::operator = (const deque<value_type>& other)
    {
        _front_array = other._front_array;
        _end_array = other._end_array;
        _front_index = other._front_index;
        _end_index = other._end_index;
        _array_count = other._array_count;
        _array_size = other._array_size;

        _container = new value_type*[_array_count];

        for(size_t i = 0; i < _array_count; ++i) {
            if (i < _front_array || i > _end_array) {
                _container[i] = nullptr;
                continue;
            }

            _container[i] = new value_type[_array_size];
            for(size_t j = (i == _front_array ? _front_index : 0); j < (i == _end_array ? _end_index : _array_size); ++j) {
                _container[i][j] = other._container[i][j];
            }
        }
    }

    template < typename value_type >
    void deque<value_type>::push_back(const value_type& element)
    {
        if (_end_index == _array_size && _end_array == _array_count - 1) {
            reallocate();
        }

        if (_end_index == _array_size) {
            ++_end_array;
            if (_container[_end_array] == nullptr) {
                _container[_end_array] = new value_type[_array_size];
            }
            _end_index = 0;
        }

        _container[_end_array][_end_index++] = element;
    }

    template < typename value_type >
    void deque<value_type>::push_front(const value_type& element)
    {
        if (_front_index == 0 && _front_array == 0) {
            reallocate();
        }

        if (_front_index == 0) {
            _front_array--;
            if (_container[_front_array] == nullptr) {
                _container[_front_array] = new value_type[_array_size];
            }
            _front_index = _array_size;
        }

        _container[_front_array][--_front_index] = element;
    }

    template < typename value_type >
    void deque<value_type>::pop_back()
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }

        if (!_end_index) {
            --_end_array;
        }
        _end_index = (_array_size + _end_index - 1) % _array_size;
    }

    template < typename value_type >
    void deque<value_type>::pop_front()
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }

        if (_front_index == _array_size - 1) {
            ++_front_array;
        }
        _front_index = (_front_index + 1) % _array_size;
    }

    template < typename value_type >
    bool deque<value_type>::empty() const
    {
        return    _front_array == _end_array && _front_index == _end_index ||
                        _front_array == _end_array + 1 && !_front_index && _end_index == _array_size;
    }

    template < typename value_type >
    size_t deque<value_type>::size() const
    {
        return (_end_array - _front_array - 1) * _array_size + _end_index + _array_size - _front_index;
    }

    template < typename value_type >
    void deque<value_type>::clear()
    {
        for(size_t i = 0; i < _array_count; i++) {
            delete[] _container[i];
        }
        delete[] _container;

        _array_count = 2;
        _front_array = _end_array = 1;
        _front_index = _end_index = 0;

        _container = new value_type*[_array_count];
        _container[1] = new value_type[_array_size];
        _container[0] = nullptr;
    }

    template < typename value_type >
    value_type& deque<value_type>::operator [] (size_t index) const
    {
        if (index >= size()) {
            throw std::out_of_range("Index out of range.");
        }
        return _container[_front_array + (index + _front_index) / _array_size][(index + _front_index) % _array_size];
    }

    template < typename value_type >
    bool deque<value_type>::operator < (const deque<value_type>& other) const
    {
        for(size_t i = 0; i < size(); i++) {
            if (i == other.size() || this->operator[](i) > other[i]) {
                return false;
            }
            if (this->operator[](i) < other[i]) {
                return true;
            }
        }
        return size() != other.size();
    }

    template < typename value_type >
    bool deque<value_type>::operator > (const deque<value_type>& other) const
    {
        return other < (*this);
    }

    template < typename value_type >
    bool deque<value_type>::operator >= (const deque<value_type>& other) const
    {
        return !(other < (*this));
    }

    template < typename value_type >
    bool deque<value_type>::operator <= (const deque<value_type>& other) const
    {
        return !(other > (*this));
    }

    template < typename value_type >
    bool deque<value_type>::operator == (const deque<value_type>& other) const
    {
        if (size() != other.size()) {
            return false;
        }

        for(size_t i = 0; i < size(); i++) {
            if (this->operator[](i) != other[i]) {
                return false;
            }
        }

        return true;
    }

    template < typename value_type >
    bool deque<value_type>::operator != (const deque<value_type>& other) const
    {
        return !(other == (*this));
    }

    template < typename value_type >
    std::ostream& operator << (std::ostream& out, const deque<value_type>& _deque)
    {
        out << '{';
        if (!_deque.empty()) {
            out << _deque[0];
        }
        for(size_t i = 1; i < _deque.size(); i++) {
            out << ", " << _deque[i];
        }
        out << "}";
        return out;
    }
}

#endif
