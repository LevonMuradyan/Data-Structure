#ifndef __QUEUE__
#define __QUEUE__
#include "..\\list\\list.h"

namespace IAM_DS 
{
  template < typename value_type >
  class queue 
  {
  public:  
    // create queue with no elements
    queue();

    // queue copy constructor
    queue(const queue&);
    
    // adds element at the back of container
    void push(const value_type&);

    // removes the front element of container
    void pop();

    // returns a reference to the front element of container
    value_type& front() const;

    // returns a reference to the back element of container
    value_type& back() const;

    // the number of elements in container
    size_t size() const;

    // checks if container is empty
    bool empty() const;

  private:
    list<value_type> _container;
  };

  template < typename value_type >
  queue<value_type>::queue() : 
    _container()
  {

  }

  template < typename value_type >
  queue<value_type>::queue(const queue<value_type>& other) :
    _container(other._container)
  {

  }

  template < typename value_type >
  void queue<value_type>::push(const value_type& element)
  {
    _container.push_back(element);
  }

  template < typename value_type >
  void queue<value_type>::pop()
  {
    _container.pop_front();
  }

  template < typename value_type >
  value_type& queue<value_type>::front() const
  {
    return *_container.begin();
  }

  template < typename value_type >
  value_type& queue<value_type>::back() const
  {
    return *(--_container.end());
  }

  template < typename value_type >
  size_t queue<value_type>::size() const
  {
    return _container.size();
  }

  template < typename value_type >
  bool queue<value_type>::empty() const
  {
    return _container.empty();
  }
}

#endif