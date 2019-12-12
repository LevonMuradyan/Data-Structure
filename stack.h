#ifndef __STACK__
#define __STACK__
#include "..\\vector\\vector.h"

namespace IAM_DS
{
    template < typename value_type >
    class stack
    {
    public:
        // create stack with no elements 
        stack();

        // stack copy constructor
        stack(const stack&);

        // adds an element at the top of the container
        void push(const value_type&);

        // removes the top element of container
        void pop();

        // the number of elements in container
        size_t size() const;

        // checks if container is empty
        bool empty() const;

        // returns a reference to the top element of container
        value_type& top() const;

    private:
        vector<value_type> _container;
    };

    template < typename value_type>
    stack<value_type>::stack() :
        _container()
    {
        
    }

    template < typename value_type>
    stack<value_type>::stack(const stack<value_type>& other) :
        _container(other._container)
    {

    }

    template < typename value_type >
    void stack<value_type>::push(const value_type& element)
    {
        _container.push_back(element);
    }

    template < typename value_type >
    void stack<value_type>::pop()
    {
        _container.pop_back();
    }

    template < typename value_type >
    size_t stack<value_type>::size() const
    {
        return _container.size();
    }

    template < typename value_type >
    bool stack<value_type>::empty() const
    {
        return _container.empty();
    }
        
    template < typename value_type >
    value_type& stack<value_type>::top() const
    {
        return _container.back();
    }
}

#endif