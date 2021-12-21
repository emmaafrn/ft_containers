#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include "pair.hpp"

template<class T>
struct node{
	node	*left;
	node	*right;
	node	*parent;
	T		*content;
};

template<class T>
class bst{
private:
	node<T>		*node;
public:
	
};

template <	class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
class map{
public:
	typedef Key                                      key_type;
	typedef T                                        mapped_type;
	typedef pair<const key_type, mapped_type>        value_type;
	typedef Compare                                  key_compare;
	typedef Allocator                                allocator_type;
	typedef typename allocator_type::reference       reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer         pointer;
	typedef typename allocator_type::const_pointer   const_pointer;
	typedef typename allocator_type::size_type       size_type;
	typedef typename allocator_type::difference_type difference_type;

	typedef implementation-defined                   iterator;
	typedef implementation-defined                   const_iterator;
	typedef std::reverse_iterator<iterator>          reverse_iterator;
	typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

private:
	bst		*bst;
public :
explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

}
template <class InputIterator>
map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
	
}
map (const map& x);

};

















#endif