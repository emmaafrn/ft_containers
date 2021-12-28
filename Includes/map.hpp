#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include "pair.hpp"
#include "map_iterator.hpp"

template<class T>
struct node{
	typedef		value_type	T;
	node		*left;
	node		*right;
	node		*parent;
	value_type	*content;

	node() : content(NULL), left(NULL), right(NULL), parent(NULL){}
	set_parent(node *previous) : parent(previous){}
	

};

template <	class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Allocator = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
class bst{
public :
typedef Key								 					key_type;
typedef T								 					mapped_type;
typedef ft::pair<const key_type, mapped_type> 				value_type;
typedef Compare												key_compare;
typedef Allocator											allocator_type;
typedef typename std::allocator_type::reference				reference;
typedef typename std::allocator_type::const_reference 		const_reference;
typedef typename std::allocator_type::pointer         		pointer;
typedef typename std::allocator_type::const_pointer   		const_pointer;
typedef typename std::allocator_type::size_type       		size_type;
typedef typename std::allocator_type::difference_type 		difference_type;
typedef implementation-defined                   iterator;
typedef implementation-defined                   const_iterator;
typedef std::reverse_iterator<iterator>          reverse_iterator;
typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
typedef typename Allocator::template rebind<node<T>>::other	n_Allocator;
private:
	node<T>			*_node;
	allocator_type	_alloc;
	key_compare		_comp;
	n_Allocator		n_alloc;

public:
	bst(){
		_node = NULL;
	}
	bst(InputIterator first, InputIterator last){
		// node<T>	*tmp;

		// _node = alloc.allocate();
		// tmp = _node;
		// tmp->parent = NULL;
		// while (first != last){
		// 	if (comp()){

		// 	}
		// 	alloc.construct(_node->content, *first);
		// 	first++;
		// }
	}
	node<T>		getNode(){
		return (_node);
	}
	ft::pair<iterator,bool> insert(node<T> **node, key_type key, mapped_type val, node<T> *previous){
		if (*node == NULL){
			*node = n_alloc.allocate();
			n_alloc.construct(*node); // ADD NODE'S CONSTRUCT
			alloc.construct((*node)->content, key, val); // PAIR'S CONSTRUCT
			(*node)->set_parent(previous);
		}
		else {
			if (comp((*node)->content->first, key))
				insert(&(*node)->left), key, val, *node);
			else if (comp(key, (*node)->content->first))
				insert(&(*node->right), key, val, *node);
			else
				return (ft::pair<ft::iterator(*node), 0>); //ADD ITERATOR
		}
	}
};

namespace	ft{

template <	class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
class map{
public:
	class iterator;
	typedef Key								 					key_type;
	typedef T								 					mapped_type;
	typedef ft::pair<const key_type, mapped_type> 				value_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef typename std::allocator_type::reference				reference;
	typedef typename std::allocator_type::const_reference 		const_reference;
	typedef typename std::allocator_type::pointer         		pointer;
	typedef typename std::allocator_type::const_pointer   		const_pointer;
	typedef typename std::allocator_type::size_type       		size_type;
	typedef typename std::allocator_type::difference_type 		difference_type;

	typedef implementation-defined                   iterator;
	typedef implementation-defined                   const_iterator;
	typedef std::reverse_iterator<iterator>          reverse_iterator;
	typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

private:
	bst<T>			_bst;
	key_compare		_comp;
	allocator_type	_alloc;
	size_type		_size;

public :
explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _bst(NULL){
}
template <class InputIterator>
map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc){
	
}
map (const map& x){

}
ft::pair<iterator,bool>	insert (const value_type& val){
	_bst.insert(_bst.getNode(), val.first, val.second, _comp, _alloc);
}
iterator insert (iterator position, const value_type& val){

}
template <class InputIterator>
void insert (InputIterator first, InputIterator last){
	
}

};

}
















#endif