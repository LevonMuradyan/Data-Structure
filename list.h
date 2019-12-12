#ifndef __LIST__
#define __LIST__
#include <iostream>
#include <stdexcept>

namespace IAM_DS
{
    template < typename value_type >
    class list
    {
    private:
        class node
        {
        public:
            // create an empty node
            node();

            // create a node with the given value
            explicit node(const value_type&);

            // create an empty node betwenn two existing nodes
            explicit node(node*, node*);

            // create a node with the given value between two existing nodes
            explicit node(const value_type&, node*, node*);

            // copy constructor
            node(const node&);

            // destructor
            // should make a bond bteween _previous and _next
            ~node();


            node* _next;
            node* _previous;
            value_type _value;

            friend class iterator;
            friend class list;
        };
    public:
        class iterator
        {
        public:
            // create an iterator that shows nowhere
            iterator();

            // copy constructor
            iterator(const iterator&);

            // destructor
            ~iterator();

            // assignment operator
            iterator& operator=(const iterator&);

            // return the referece to the value of the node shown by this iterator
            value_type& operator*();

            // increasment and decreasment operators, shold show the next or the previous node
            iterator& operator++();    // prefix
            iterator operator++(int);  // postfix
            iterator& operator--();    // prefix
            iterator operator--(int);  // postfix

            bool operator==(const iterator&) const;
            bool operator!=(const iterator&) const;

        private:

            // create an iterator that shows at the given node
            iterator(node*);

            list<value_type>::node *_node;
            friend class node;
            friend class list;
        };

    public:

        // create an empty list
        list();

        // create a list of the given size
        explicit list(const size_t);

        // create a list list of the given size, wih the given values
        explicit list(const size_t, const value_type&);

        // copy constructor
        list(const list&);

        // destructor, should clear the memory
        ~list();


        // assignment operator
        list& operator=(const list&);


        // answer if the list is empty
        bool empty()  const;

        // return the size of the list (number of elements in it)
        size_t size() const;


        // return an iterator that shows the first element in the list
        iterator begin() const;
        // return an iterator that shows the 'end' of the list
        iterator end()   const;

        // insert an element of the given value before the element shown by the givn iterator
        void insert(const iterator, const value_type&);

        // erase the element shown by the given iterator and make the iterator show it's next element
        void erase(iterator);

        // add an element in the end of the list
        void push_back(const value_type&);
        // erase the last element from the list
        void pop_back();
        // insert an element in the front of the lst
        void push_front(const value_type&);
        // erase the first element from the list
        void pop_front();

        // clear the list
        void clear();

    private:
        node* _end;
        node* _begin;
        size_t _size;

        friend class node;
        friend class iterator;
    };

    //////////////////////////////////////////////////////////////////////////////////////


    template<typename value_type>
    list<value_type>::node::node() :
        _next(nullptr),
        _previous(nullptr)
    {

    }


    template<typename value_type>
    list<value_type>::node::node(const value_type& value) :
        _value(value),
        _next(nullptr),
        _previous(nullptr)
    {

    }


    template<typename value_type>
    list<value_type>::node::node(node* previous, node* next) :
        _next(next),
        _previous(previous)
    {
        if (next != nullptr) {
            next->_previous = this;
        }
        if (previous != nullptr) {
            previous->_next = this;
        }
    }


    template<typename value_type>
    list<value_type>::node::node(const value_type& value, node* previous, node* next) :
        _value(value),
        _next(next),
        _previous(previous)
    {
        if (next != nullptr) {
            next->_previous = this;
        }
        if (previous != nullptr) {
            previous->_next = this;
        }
    }


    template<typename value_type>
    list<value_type>::node::node(const node& other) :
        _value(other->_value),
        _next(other->_next),
        _previous(other->_previous)
    {

    }


    template<typename value_type>
    list<value_type>::node::~node()
    {
        if (_previous != nullptr) {
            _previous->_next = _next;
        }
        if (_next != nullptr) {
            _next->_previous = _previous;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////

    template < typename value_type >
    list<value_type>::iterator::iterator() :
        _node(nullptr)
    {

    }


    template < typename value_type >
    list<value_type>::iterator::iterator(const list<value_type>::iterator& other) :
        _node(other._node)
    {

    }


    template < typename value_type >
    list<value_type>::iterator::iterator(node* __node) :
        _node(__node)
    {

    }


    template < typename value_type >
    list<value_type>::iterator::~iterator()
    {

    }


    template < typename value_type >
    typename list<value_type>::iterator& list<value_type>::iterator::operator=(
                                                    const list<value_type>::iterator& other
                                                    )
    {
        _node = other._node;
    }


    template < typename value_type >
    value_type& list<value_type>::iterator::operator*()
    {
        if (_node == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (_node->_next == nullptr) {
            throw std::logic_error("Cannot access endpoint value.");
        }

        return _node->_value;
    }


    template < typename value_type >
    typename list<value_type>::iterator list<value_type>::iterator::operator++(int)
    {
        if (_node == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (_node->_next == nullptr) {
            throw std::logic_error("Cannot ++.");
        }

        _node = _node->_next;
        return (*this);
    }


    template < typename value_type >
    typename list<value_type>::iterator& list<value_type>::iterator::operator++()
    {
        if (_node == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (_node->_next == nullptr) {
            throw std::logic_error("Cannot ++.");
        }

        list<value_type>::iterator temp(*this);

        _node = _node->_next;
        return (*this);
    }


    template < typename value_type >
    typename list<value_type>::iterator list<value_type>::iterator::operator--(int)
    {
        if (_node == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (_node->_previous == nullptr) {
            throw std::logic_error("Cannot --.");
        }

        _node = _node->_previous;
        return (*this);
    }


    template < typename value_type >
    typename list<value_type>::iterator& list<value_type>::iterator::operator--()
    {
        if (_node == nullptr) {
            throw std::logic_error("The iterator shows nowhere.");
        }

        if (_node->_previous == nullptr) {
            throw std::logic_error("Cannot --.");
        }

        list<value_type>::iterator temp(*this);

        _node = _node->_previous;
        return (*this);
    }


    template < typename value_type >
    bool list<value_type>::iterator::operator==(const list<value_type>::iterator& other) const
    {
        if (_node == nullptr || other._node == nullptr) {
            throw std::logic_error("One of the iterators shows nowhere.");
        }

        return _node == other._node;
    }


    template < typename value_type >
    bool list<value_type>::iterator::operator!=(const list<value_type>::iterator& other) const
    {
        return _node != other._node;
    }

//////////////////////////////////////////////////////////////////////////////////////

    template < typename value_type >
    list<value_type>::list() :
        _end(new node()),
        _begin(_end),
        _size(0)
    {

    }


    template < typename value_type >
    list<value_type>::list(const size_t n) :
        _end(new node()),
        _begin(_end),
        _size(n)
    {
        iterator it = _begin;
        for (int i = 0; i < n; ++i) {
            _begin = new node(nullptr, _begin);
        }
    }


    template < typename value_type >
    list<value_type>::list(const size_t n, const value_type& val) :
        _end(new node()),
        _begin(_end),
        _size(n)
    {
        for (int i = 0; i < n; ++i) {
            _begin = new node(val,  nullptr, _begin);
        }
    }


    template < typename value_type >
    list<value_type>::list(const list<value_type>& other) :
        _end(new node()),
        _begin(_end)
    {
        node *cur = new node(_end);
        for (iterator it = other.begin(); it != other.end(); ++it) {
            cur = new node(*it, cur, _end);
            _begin = _begin->_previous;
        }
    }


    template < typename value_type >
    list<value_type>::~list()
    {
        clear();
        delete _end;
    }


    template < typename value_type >
    list<value_type>& list<value_type>::operator=(const list<value_type>& other)
    {
        clear();
        node *cur = new node(_end);
        for (iterator it = other.begin(); it != other.end(); ++it) {
            cur = new node(*it, cur, _end);
            _begin = _begin->_previous;
        }
    }


    template < typename value_type >
    bool list<value_type>::empty() const
    {
        return _size == 0;
    }


    template < typename value_type >
    size_t list<value_type>::size() const
    {
        return _size;
    }


    template < typename value_type >
    typename list<value_type>::iterator list<value_type>::begin() const
    {
        return iterator(_begin);
    }


    template < typename value_type >
    typename list<value_type>::iterator list<value_type>::end() const
    {
        return iterator(_end);
    }


    template < typename value_type >
    void list<value_type>::insert(const iterator it, const value_type& val)
    {
        _size++;
        new node(val, it._node->_previous, it._node);
        if (it == begin()) {
            _begin = _begin->_previous;
        }
    }


    template < typename value_type >
    void list<value_type>::erase(iterator it)
    {
        if (it == end() || it._node == nullptr) {
            throw std::invalid_argument("Cannot erase the \'end\'.");
        }

        if (it == begin()) {
            _begin = _begin->_next;
        }

        _size--;
        node* _tmp = it._node;
        ++it;
        delete _tmp;
    }


    template < typename value_type >
    void list<value_type>::push_back(const value_type& val)
    {
        insert(end(), val);
    }


    template < typename value_type >
    void list<value_type>::pop_back()
    {
        if (empty()) {
            throw std::logic_error("The list is empty.");
        }

        iterator it = end();
        it--;
        erase(it);
    }


    template < typename value_type >
    void list<value_type>::push_front(const value_type& val)
    {
        insert(begin(), val);
    }


    template < typename value_type >
    void list<value_type>::pop_front()
    {
        if (empty()) {
            throw std::logic_error("The list is empty.");
        }

        erase(begin());
    }


    template < typename value_type >
    void list<value_type>::clear()
    {
        while (!empty()) {
            pop_front();
        }
    }
}

#endif
