#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
#include <stdexcept>

namespace DS
{
    template < typename T >
    class vector {

        private:
            size_t _size;
            size_t _capacity;
            T* _container;

            /// checks if memory shoud be reallocated and reallocate
            void check_and_reallocate();
            friend class iterator;

        public:
            class iterator {

                private:
                    T* v_ptr;
                    friend class vector;

                public:
                    /// create an iterator that shows nowhere
                    iterator();

                    /// copy constructor
                    iterator(const iterator&);

                    iterator(T* ptr);

                    /// destructor
                    ~iterator();

                    /// assignment operator
                    iterator& operator=(const iterator&);

                    /// return the referece to the value of the vector shown by this iterator
                    T& operator*();
            
                    /// return the referece to the value of the vector shown by this iterator
                    T& operator[](size_t) const;

                    /// increasment and decreasment operators, shold show the next or the previous node
                    iterator& operator++();    // prefix
                    iterator operator++(int);  // postfix
                    iterator& operator--();    // prefix
                    iterator operator--(int);  // postfix

                    /// addition, subtraction by number 
                    iterator operator+(size_t) const;
                    iterator operator-(size_t) const;
            
                    /// boolean operators comparing two iterators
                    bool operator<=(const iterator&) const;
                    bool operator>=(const iterator&) const;
                    bool operator==(const iterator&) const;
                    bool operator!=(const iterator&) const;        
            };

        public:

            /// create a vector with no elements
            vector();

            /// vector copy constructor
            vector(const vector&);

            /// create a vector with a given sequence of data of type "T"
            vector(const T*, size_t);

            /// create a vector with default constructed elements
            explicit vector(const size_t);

            /// create a vector with defalult elements
            vector(const size_t, const T&);

            /// create a vector with initialization list
            vector(std::initializer_list<T> const&);

            /// destructor
            /// clears the "_container"
            ~vector();

            /// vecor assignment operator
            vector<T>& operator=(const vector<T>&);

            /// add an element to the end of the vector
            void push_back(const T&);

            /// remove an element from the end of the vector
            void pop_back();

            /// return the number of elements in the vector
            size_t size() const;

            size_t capacity() const;

            /// check if the vector is empty
            bool empty() const;

            /// return the referece to the element in the vector at the given position
            /// throw an exception if the key is not valid
            T& operator[](size_t) const;

            /// return the referece to the vector 
            vector<T>& operator=(std::initializer_list<T>&);

            /// output the vector in this format: {element0, element1, ...}
            friend std::ostream& operator<<(std::ostream&, const vector&);

            /// return iterator of the first element in the vector
            vector<T>::iterator begin() const;

            /// return iterator of the endpoint in the vector
            vector<T>::iterator end() const;

            /// return reverse iterator to reverse beginning in the vector
            vector<T>::iterator rbegin() const;

            /// return reverse iterator to reverse end in the vector
            vector<T>::iterator rend() const;

            /// return the first element of the vector
            T& front() const;

            /// return the last element of the vector
            T& back() const;

            /// insert an element befor the given position
            /// throw an exception if the given position is not in the valid range: [0, this->size()]
            void insert(const T&, const size_t);

            /// removes the element at the given position
            /// throws an exception if the given position is not in the valid range: [0, this->size()]
            void erase(const size_t);

            /// clears the vector
            void clear();

            /// compares this vector and the given one lexicographically
            bool operator<(const vector&) const;
            bool operator>(const vector&) const;
            bool operator==(const vector&) const;
            bool operator!=(const vector&) const;
            bool operator<=(const vector&) const;
            bool operator>=(const vector&) const;

    };

    //////////////////////////////////////////////////////////////////////////////////////

    template < typename T >
    vector<T>::iterator::iterator() :
        v_ptr(nullptr)
    {

    }

    template < typename T >
    vector<T>::iterator::iterator(const vector<T>::iterator& other) :
        v_ptr(other.v_ptr)
    {

    }

    template < typename T >
    vector<T>::iterator::iterator(T* ptr) :
        v_ptr(ptr)
    {

    }

    template < typename T >
    vector<T>::iterator::~iterator()
    {
       
    }

    template < typename T >
    typename vector<T>::iterator& vector<T>::iterator::operator=(
        const vector<T>::iterator& other
        )
    {
        v_ptr = other.v_ptr;
        return (*this);
    }

    template < typename T >
    T& vector<T>::iterator::operator*()
    {
        if (v_ptr == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        return *v_ptr;
    }

    template<typename T>
    T& vector<T>::iterator::operator[](size_t index) const
    {
        return *(v_ptr + index);
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::iterator::operator++(int)
    {
        if (v_ptr == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (v_ptr + 1 == nullptr) {
            throw std::logic_error("Cannot ++.");
        }

        vector<T>::iterator temp(*this);
        v_ptr = v_ptr + 1;
        return temp;
    }

    template < typename T >
    typename vector<T>::iterator& vector<T>::iterator::operator++()
    {
        if (v_ptr == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (v_ptr + 1 == nullptr) {
            throw std::logic_error("Cannot ++.");
        }

        v_ptr = v_ptr + 1;
        return (*this);
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::iterator::operator--(int)
    {
        if (v_ptr == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (v_ptr - 1 == nullptr) {
            throw std::logic_error("Cannot --.");
        }

        vector<T>::iterator temp(*this);
        v_ptr = v_ptr - 1;
        return temp;
    }

    template < typename T >
    typename vector<T>::iterator& vector<T>::iterator::operator--()
    {
        if (v_ptr == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (v_ptr - 1 == nullptr) {
            throw std::logic_error("Cannot --.");
        }

        v_ptr = v_ptr - 1;
        return (*this);
    }
    
    template<typename T>
    typename vector<T>::iterator vector<T>::iterator::operator+(size_t num) const
    {
        return vector<T>::iterator(v_ptr + num);
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::iterator::operator-(size_t num) const
    {
        return vector<T>::iterator(v_ptr - num);
    }

    template<typename T>
    bool vector<T>::iterator::operator<=(const vector<T>::iterator& other) const
    {
        if (v_ptr == nullptr || other.v_ptr == nullptr) {
            throw std::logic_error("One of the iterators shows nowhere.");
        }
        return v_ptr <= other.v_ptr;
    }

    template<typename T>
    bool vector<T>::iterator::operator>=(const vector<T>::iterator& other) const
    {
        if (v_ptr == nullptr || other.v_ptr == nullptr) {
            throw std::logic_error("One of the iterators shows nowhere.");
        }
        return other.v_ptr <= v_ptr;
    }

    template < typename T >
    bool vector<T>::iterator::operator==(const vector<T>::iterator& other) const
    {
        if (v_ptr == nullptr || other.v_ptr == nullptr) {
            throw std::logic_error("One of the iterators shows nowhere.");
        }

        return v_ptr == other.v_ptr;
    }

    template < typename T >
    bool vector<T>::iterator::operator!=(const vector<T>::iterator& other) const
    {
        if (v_ptr == nullptr || other.v_ptr == nullptr) {
            throw std::logic_error("One of the iterators shows nowhere.");
        }
        return v_ptr != other.v_ptr;
    }

    //////////////////////////////////////////////////////////////////////////////////////

    template < typename T >
    void vector<T>::check_and_reallocate()
    {
        std::cout << "Check and reallocate" << std::endl;
        if (_size > _capacity) {
            _capacity <<= 1;
            T* new_container = new T[_capacity];
            for (int i = 0; i < _size - 1; ++i)
                new_container[i] = _container[i];
            delete[] _container;
            _container = new_container;
        }
        else if ((_size << 2) < _capacity && _capacity > (1 << 8)) {
            _capacity >>= 1;
            T* new_container = new T[_capacity];
            for (int i = 0; i < _size; ++i)
                new_container[i] = _container[i];
            delete[] _container;
            _container = new_container;
        }
    }

    template < typename T >
    vector<T>::vector() :
        _capacity(0),
        _size(0),
        _container(new T[_capacity])
    {
        std::cout << "Default Constructor" << std::endl;
    }

    template < typename T >
    vector<T>::vector(const vector<T>& other) :
        _capacity(other._capacity),
        _size(other._size),
        _container(new T[_capacity])
    {
        std::cout << "Copy Constructor" << std::endl;
        for (size_t i = 0; i < _size; ++i)
            _container[i] = other._container[i];
    }

    /// New Capacity
    template < typename T >
    vector<T>::vector(const T* sequence, size_t sequence_size) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new T[_capacity])
    {
        std::cout << "2 args Constructor with array and size" << std::endl;
        for (size_t i = 0; i < sequence_size; ++i)
            _container[i] = sequence[i];
    }

    template < typename T >
    vector<T>::vector(size_t sequence_size) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new T[_capacity])
    {
        std::cout << "1 arg Constructor" << std::endl;
        for (size_t i = 0; i < sequence_size; ++i)
            _container[i] = 0;

    }

    template < typename T >
    vector<T>::vector(const size_t sequence_size, const T& value) :
        _capacity(sequence_size),
        _size(sequence_size),
        _container(new T[_capacity])
    {
        std::cout << "2 args Constructor" << std::endl;
        for (size_t i = 0; i < sequence_size; ++i)
            _container[i] = value;
    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> const& init) :
        _capacity(init.size()),
        _size(0),
        _container(new T[_capacity])
    {
        std::cout << "initialization list Constructor" << std::endl;
        for (const T& elem : init)
            _container[_size++] = elem;

    }

    template < typename T >
    vector<T>::~vector()
    {
        std::cout << "Destructor" << std::endl;
        delete[] _container;
    }

    template < typename T >
    vector<T>& vector<T>::operator=(const vector<T>& other)
    {
        std::cout << "Operator= vector" << std::endl;
        _capacity = other._capacity;
        _size = other._size;
        delete[] _container;
        _container = new T[_capacity];

        for (size_t i = 0; i < _size; ++i)
            _container[i] = other._container[i];

        return (*this);
    }

    template < typename T >
    void vector<T>::push_back(const T& element)
    {
        std::cout << "push_back" << std::endl;
        _size++;
        check_and_reallocate();
        _container[_size - 1] = element;
    }

    template < typename T >
    void vector<T>::pop_back()
    {
        std::cout << "pop_back" << std::endl;
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }

        _size--;
        check_and_reallocate();
    }

    template < typename T >
    size_t vector<T>::size() const
    {
        std::cout << "rerturn size" << std::endl;
        return _size;
    }

    template < typename T >
    size_t vector<T>::capacity() const
    {
        std::cout << "return capacity" << std::endl;
        return _capacity;
    }

    template < typename T >
    bool vector<T>::empty() const
    {
        std::cout << "empty" << std::endl;
        return _size == 0;
    }

    template < typename T >
    T& vector<T>::operator[](size_t index) const
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of range.");
        }
        return _container[index];
    }

    template < typename T >
    vector<T>& vector<T>::operator= (std::initializer_list<T>& init)
    {   
        std::cout << "operator= initialization list" << std::endl;
        _size = 0;
        _capacity = init.size();
         delete[] _container;
        _container = new T[_capacity];
        
        for (const T& elem : init)
            _container[_size++] = elem;

        return (*this);
    }

    template < typename T >
    std::ostream& operator<<(std::ostream& out, const vector<T>& vector)
    {
        std::cout << "operator <<" << std::endl;
        out << "{ ";
        if (!vector.empty()) {
            out << vector[0];
        }
        for (size_t i = 1; i < vector.size(); ++i) {
            out << ", " << vector[i];
        }
        out << " }";
        return out;
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::begin() const
    {
        return vector<T>::iterator(_container);
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::end() const
    {
        return vector<T>::iterator(_container + _size);
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::rbegin() const
    {
        return vector<T>::iterator(_container + _size - 1);
    }

    template < typename T >
    typename vector<T>::iterator vector<T>::rend() const
    {
        return vector<T>::iterator(_container -1);
    }

    template < typename T >
    T& vector<T>::front() const
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }
        return _container[0];
    }

    template < typename T >
    T& vector<T>::back() const
    {
        if (empty()) {
            throw std::runtime_error("The container is empty.");
        }
        return _container[_size - 1];
    }

    template < typename T >
    void vector<T>::insert(const T& element, const size_t position)
    {
        if (position >= _size) {
            throw std::out_of_range("Index out of range.");
        }

        _size++;
        check_and_reallocate();

        for (size_t i = _size - 1; i >= position + 1; --i) {
            _container[i] = _container[i - 1];
        }
        _container[position] = element;
    }

    template < typename T >
    void vector<T>::erase(const size_t position)
    {
        if (position > _size) {
            throw std::out_of_range("Index out of range.");
        }

        _size--;
        check_and_reallocate();

        for (size_t i = position; i < _size; ++i) {
            _container[i] = _container[i + 1];
        }
    }

    template < typename T >
    void vector<T>::clear()
    {
        _size = 0;
        _capacity = 2;
        delete[] _container;
        _container = new T[_capacity];
    }

    template < typename T >
    bool vector<T>::operator<(const vector<T>& other) const
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

    template < typename T >
    bool vector<T>::operator>(const vector<T>& other) const
    {
        return (other < *this);
    }

    template < typename T >
    bool vector<T>::operator==(const vector<T>& other) const
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

    template < typename T >
    bool vector<T>::operator!=(const vector<T>& other) const
    {
        return !(*this == other);
    }

    template < typename T >
    bool vector<T>::operator<=(const vector<T>& other) const
    {
        return !(*this > other);
    }

    template < typename T >
    bool vector<T>::operator>=(const vector<T>& other) const
    {
        return !(*this < other);
    }

}

#endif // _VECTOR_
