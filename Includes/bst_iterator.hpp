#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

#include <cstddef>
#include <iostream>


namespace ft {

template <class Node, class T, class mapped> class bst_iterator {
public:
  typedef T value_type;
  typedef value_type *pointer;
  typedef mapped mapped_type;
  typedef mapped_type &reference;
  typedef Node *node_pointer;
  typedef ptrdiff_t difference_type;
  typedef std::bidirectional_iterator_tag	iterator_category;

  bst_iterator() : _elem() {}

  bst_iterator(node_pointer ptr) : _elem(ptr) {}

  value_type &operator*() { 
    return _elem->value; }

  pointer operator->() { return &_elem->value; }

  reference operator[](int x) {
    return _elem[x];
  }

  node_pointer base() const { return _elem; }

  bst_iterator &operator++(void) {
    if (_elem->r) {
      _elem = _elem->r;
      while (_elem->l) {
        _elem = _elem->l;
      }
    } else {
      while (_elem && _elem->p && _elem->p->r == _elem) {
        _elem = _elem->p;
      }
      _elem = _elem->p;
    }
    return (*this);
  }

  bst_iterator operator++(int) {
    bst_iterator tmp(*this);

    this->operator++();
    return (tmp);
  }
  bst_iterator operator--() {
    if (_elem->l) {
      _elem = _elem->l;
      while (_elem->r) {
        _elem = _elem->r;
      }
    } else {
      while (_elem->p && _elem->p->l == _elem) {
        _elem = _elem->p;
      }
      _elem = _elem->p;
    }
    return (*this);
  }

  bst_iterator operator--(int) {
    bst_iterator tmp(*this);

    this->operator--();
    return (tmp);
  }

  friend bool operator==(const bst_iterator rhs, const bst_iterator lhs) {
    return rhs._elem == lhs._elem;
  }

  friend bool operator!=(const bst_iterator rhs, const bst_iterator lhs) {
    return rhs._elem != lhs._elem;
  }

  


private:
  node_pointer _elem;
};
} // namespace ft

#endif