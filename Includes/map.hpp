#ifndef MAP_HPP
#define MAP_HPP

#include "bst.hpp"
#include "ReverseIterator.hpp"
#include "bst_node.hpp"
#include "pair.hpp"
#include <cstddef>
#include <memory>

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef ft::bst_node<value_type> Node;
  typedef Alloc allocator_type;
  typedef typename Alloc::template rebind<Node>::other node_allocator;
  class value_compare : Compare{
    public :
    bool operator()(value_type x, value_type y){
      return Compare()(x.first, y.first);
    }
  };

private:
  typedef bst<value_type, key_type, mapped_type, key_compare, node_allocator> __bst;

public:
  typedef typename Alloc::template rebind<__bst>::other bst_allocator;
  typedef typename __bst::iterator iterator;
  typedef typename __bst::const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef typename __bst::size_type size_type;

public:
  explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()){
    _bst_alloc = bst_allocator();
    _bst = _bst_alloc.allocate(1);
    _const_bst = _bst;
    _bst_alloc.construct(_bst, alloc, comp);
  }
  template <class InputIterator>
  map (InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type()){
    _bst_alloc = bst_allocator();
    _bst = _bst_alloc.allocate(1);
    _const_bst = _bst;
    _bst_alloc.construct(_bst, alloc, comp);
    _bst->insert(first, last);
  }
  map (const map& x){
    _bst_alloc = bst_allocator();
    _bst = _bst_alloc.allocate(1);
    _const_bst = _bst;
    _bst_alloc.construct(_bst, *x._bst);
  }
  ~map(){
    _bst_alloc.destroy(_bst);
    _bst_alloc.deallocate(_bst, 1);
  }

  ft::pair<iterator, bool> insert(const value_type &val) {
    return _bst->insert(val);
  }
  iterator insert (iterator position, const value_type& val){
    position = NULL;
    return iterator(_bst->insert(val));
  }
  template <class InputIterator>
  void insert (InputIterator first, InputIterator last){
    while (first != last){
      _bst->insert(*first);
      first++;
    }
  }

  size_type erase(const key_type &k) {
	  iterator tmp = find(k);
	  
	  if (tmp != end()){
	    _bst->erase(tmp);
		  return 1;
	  }
	  return 0;
  }
  void erase(iterator pos) { _bst->erase(pos); }
  void erase (iterator first, iterator last){
    key_type  tmp;
    while (first != last){
      tmp = first->first;
      first++;
		  erase(tmp);
	  }
  }

  void swap (map& x){
    std::swap(_bst, x._bst);
    std::swap(_const_bst, x._const_bst);
  }

  iterator find(const key_type &k)  { return _bst->find(k); }
  const_iterator find(const key_type &k) const { return _const_bst->find(k); }
  bool empty() const { return _bst->empty(); }
  size_type size() const{ return _bst->size(); }
  size_type max_size() const{ return _bst->max_size(); }
  const_iterator begin() const { return _const_bst->begin(); }
  iterator begin() { return _bst->begin(); }
  const_iterator end() const { return _const_bst->end();}
  iterator end() { return _bst->end(); }
  reverse_iterator rend() { return _bst->rend(); }
  const_reverse_iterator rend() const { return _const_bst->rend(); }
  reverse_iterator rbegin() { return _bst->rbegin(); }
  const_reverse_iterator rbegin() const { return _const_bst->rbegin(); }
  key_compare key_comp() const{ return (*_bst).key_comp();}
  value_compare value_comp() const{ return value_compare();}
  iterator lower_bound (const key_type& k){ return _bst->lower_bound(k);}
  const_iterator lower_bound (const key_type& k) const{ return _bst->lower_bound(k);}
  iterator upper_bound (const key_type& k){ return _bst->upper_bound(k);}
  const_iterator upper_bound (const key_type& k) const{ return _bst->upper_bound(k);}
  size_type count (const key_type& k) const{ return find(k).base() != end().base(); }
  pair<const_iterator,const_iterator> equal_range (const key_type& k) const{ return _bst->equal_range(k); }
  pair<iterator,iterator> equal_range (const key_type& k){ return _bst->equal_range(k);}
  void clear(){ _bst->clear(); }
  allocator_type get_allocator() const{ return allocator_type(); }
  void    ft_print(size_type x){ _bst->ft_printTree(x); }
  map& operator= (const map& x){
    clear();
    _bst_alloc.destroy(_bst);
    _bst_alloc.construct(_bst, *x._bst);
    return (*this);
  }
    mapped_type& operator[] (const key_type& k){
    return _bst->operator[](k);
  }
private:
  __bst *_bst;
  const __bst *_const_bst;
  bst_allocator _bst_alloc;
};
  template <class Key, class T, class Compare, class Alloc>
  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){
    x.swap(y);
  }
}

#endif