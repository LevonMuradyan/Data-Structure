#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
#include <stdexcept>

namespace IAM_DS
{
    template < typename value_type >
    class    vector
    {
    public:
        // create a vector with no elements
        vector();

        // vector copy constructor
        vector(const vector &);

        // create a vector with a given sequence of data of type "value_type"
        explicit vector(const value_type*, size_t size);

        // create a vector with default constructed elements
        explicit vector(const size_t);

        // create a vector with defalult elements
        explicit vector(const size_t, const value_type&);

        // destructor
        // clears the "_container"
        ~vector();

        // vecor assignment operator
        vector<value_type>& operator=(const vector<value_type>&);

        // add an element to the end of the vector
        void push_back(const value_type&);

        // remove an element from the end of the vector
        void pop_back();

        // return the number of elements in the vector
        size_t size() const;

        // check if the vector is empty
        bool empty() const;

        // return the referece to the element in the vector at the given position
        // throw an exception if the key is not valid
        value_type& operator[](size_t) const;

        // output the vector in this format: {element0, element1, ...}
        //friend std::ostream& operator<<(std::ostream&, const vector&);

        // return the address of the first element in the vector
        value_type* begin() const;

        // return the address of the endpoint in the vector
        value_type* end() const;

        // return the first element of the vector
        value_type& front() const;

        // return the last element of the vector
        value_type& back() const;

        // insert an element befor the given position
        // throw an exception if the given position is not in the valid range: [0, this->size()]
        void insert(const value_type&, const size_t);

        // removes the element at the given position
        // throws an exception if the given position is not in the valid range: [0, this->size()]
        void erase(const size_t);

        // clears the vector
        void clear();

        // compares this vector and the given one lexicographically
        bool operator<(const vector&) const;
        bool operator>(const vector&) const;
        bool operator==(const vector&) const;
        bool operator!=(const vector&) const;
        bool operator<=(const vector&) const;
        bool operator>=(const vector&) const;

    private:
        size_t _size;
        size_t _capacity;
        value_type *_container;

        // checks if memory shoud be reallocated and reallocate
        void check_and_reallocate();
    };

    template < typename value_type >
    void vector<value_type>::check_and_reallocate()
    {
        if (_size > _capacity) {
            _capacity <<= 1;
            value_type *new_container = new value_type[_capacity];
            for(int i = 0; i < _size - 1; ++i)
                new_container[i] = _container[i];
            delete[] _container;
            _container = new_container;
        }
        else if ((_size << 2) < _capacity && _capacity > (1 << 8)) {
            _capacity >>= 1;
            value_type *new_container = new value_type[_capacity];
            for(int i = 0; i < _size; ++i)
                new_container[i] = _container[i];
            delete[] _container;
            _container = new_container;
        }
    }

    template < typename value_type >
    vector<value_type>::vector() :
        _capacity(2),
        _size(0),
        _container(new value_type[_capacity])
    {

    }

    template < typename value_type >
    vector<value_type>::vector(const vector<value_type>& other) :
        _capacity(other._capacity),
        _size(other._size),
        _container(new value_type[_capacity])
    {
        for(size_t i = 0; i < _size; ++i)
            _container[i] = other._container[i];
    }

    // TODO: New Capacity
    template < typename value_type >
    vector<value_type>::vector(const value_type* sequence, size_t sequence_size) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new value_type[_capacity])
    {
        for(size_t i = 0; i < sequence_size; ++i)
            _container[i] = sequence[i];
    }

    template < typename value_type >
    vector<value_type>::vector(size_t sequence_size) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new value_type[_capacity])
    {

    }

    template < typename value_type >
    vector<value_type>::vector(const size_t sequence_size, const value_type& value) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new value_type[_capacity])
    {
        for(size_t i = 0; i < sequence_size; ++i)
            _container[i] = value;
    }

    template < typename value_type >
    vector<value_type>::~vector()
    {
        delete[] _container;
    }

    template < typename value_type >
    vector<value_type>& vector<value_type>::operator=(const vector<value_type>& other)
    {
        _capacity = other._capacity;
        _size = other._size;
        delete[] _container;
        _container = new value_type[_capacity];

        for (size_t i = 0; i < _size; ++i)
            _container[i] = other._container[i];

        return (*this);
    }

    template < typename value_type >
    void vector<value_type>::push_back(const value_type& element)
    {
        _size++;
        check_and_reallocate();
        _container[_size - 1] = element;
    }

    template < typename value_type >
    void vector<value_type>::pop_back()
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }

        _size--;
        check_and_reallocate();
    }

    template < typename value_type >
    size_t vector<value_type>::size() const
    {
        return _size;
    }

    template < typename value_type >
    bool vector<value_type>::empty() const
    {
        return _size == 0;
    }

    template < typename value_type >
    value_type& vector<value_type>::operator[](size_t index) const
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of range.");
        }
        return _container[index];
    }

    template < typename value_type >
    std::ostream& operator<<(std::ostream& out, const vector<value_type>& vector)
    {
        out << "{ ";
        if (!vector.empty()) {
            out << vector[0];
        }
        for(size_t i = 1; i < vector.size(); ++i) {
            out << ", " << vector[i];
        }
        out << " }";
        return out;
    }

    template < typename value_type >
    value_type* vector<value_type>::begin() const
    {
        return _container;
    }

    template < typename value_type >
    value_type* vector<value_type>::end() const
    {
        return _container + _size;
    }

    template < typename value_type >
    value_type& vector<value_type>::front() const
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }
        return _container[0];
    }

    template < typename value_type >
    value_type& vector<value_type>::back() const
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }
        return _container[_size - 1];
    }

    template < typename value_type >
    void vector<value_type>::insert(const value_type& element, const size_t position)
    {
        if (position >= _size) {
                throw std::out_of_range("Index out of range.");
        }

        _size++;
        check_and_reallocate();

        for (size_t i = _size-1; i >= position+1; --i) {
            _container[i] = _container[i-1];
        }
        _container[position] = element;
    }

    template < typename value_type >
    void vector<value_type>::erase(const size_t position)
    {
        if (position > _size) {
                throw std::out_of_range("Index out of range.");
        }

        _size--;
        check_and_reallocate();

        for (size_t i = position; i < _size; ++i) {
            _container[i] = _container[i+1];
        }
    }

    template < typename value_type >
    void vector<value_type>::clear()
    {
        _size = 0;
        _capacity = 2;
        delete[] _container;
        _container = new value_type[_capacity];
    }

    template < typename value_type >
    bool vector<value_type>::operator<(const vector<value_type>& other) const
    {
        if (other.empty()) {
                return false;
        }
        size_t limit = (_size < other.size()) ? _size : other.size();

        for (size_t i = 0; i < limit; ++i) {
            if (_container[i] < other[i]) {
                return true;
            }
            if (other[i] < _container[i]) {
                return false;
            }
        }

        return _size < other.size();
    }

    template < typename value_type >
    bool vector<value_type>::operator>(const vector<value_type>& other) const
    {
        return (other < *this);
    }

    template < typename value_type >
    bool vector<value_type>::operator==(const vector<value_type>& other) const
    {
        if (_size != other.size()) {
            return false;
        }
        for (size_t i = 0; i < _size; ++i) {
            if (_container[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    template < typename value_type >
    bool vector<value_type>::operator!=(const vector<value_type>& other) const
    {
        return !(*this == other);
    }

    template < typename value_type >
    bool vector<value_type>::operator<=(const vector<value_type>& other) const
    {
        return !(*this > other);
    }

    template < typename value_type >
    bool vector<value_type>::operator>=(const vector<value_type>& other) const
    {
        return !(*this < other);
    }
}

#endif
