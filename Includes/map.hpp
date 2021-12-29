#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include "pair.hpp"
#include "map_iterator.hpp"

namespace	ft{
	template<class T>
	struct Node{
		typedef		T		value_type;
		Node		*left;
		Node		*right;
		Node		*parent;
		value_type	*content;

		Node() : content(NULL), left(NULL), right(NULL), parent(NULL){}
		void	set_parent(Node *previous){
			parent = previous;
		}	

	};

	template <	class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = std::less<Key>,                     // map::key_compare
				class Allocator = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
	class bst{
	public :
	typedef Key								 					key_type;
	typedef T								 					mapped_type;
	typedef	Node<T>												node;
	typedef	node*												node_ptr;
	typedef ft::pair<const key_type, mapped_type> 				value_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference 		const_reference;
	typedef typename allocator_type::pointer         		pointer;
	typedef typename allocator_type::const_pointer   		const_pointer;
	typedef typename allocator_type::size_type       		size_type;
	typedef typename allocator_type::difference_type 		difference_type;
	typedef ft::iterator<T>									iterator;
	typedef const ft::iterator<T>							const_iterator;
	typedef std::reverse_iterator<iterator>					reverse_iterator;
	typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef typename Allocator::template rebind<node>::other	n_Allocator;
	private:
		node_ptr		_node;
		allocator_type	_alloc;
		key_compare		_comp;
		n_Allocator		n_alloc;

	public:
		bst(allocator_type alloc, key_compare comp) : _alloc(alloc), _comp(comp), _node(NULL), n_alloc(){}
		// template <class InputIterator>
		// bst(InputIterator first, InputIterator last){
			
		// }
		node	getNode(){
			return (_node);
		}
		ft::pair<iterator,bool> insert(node **node, key_type key, mapped_type val, node_ptr previous){
			if (*node == NULL){
				*node = n_alloc.allocate();
				n_alloc.construct(*node); // ADD NODE'S CONSTRUCT
				_alloc.construct((*node)->content, key, val); // PAIR'S CONSTRUCT
				(*node)->set_parent(previous);
			}
			else {
				if (comp((*node)->content->first, key))
					insert((&(*node)->left), key, val, *node);
				else if (comp(key, (*node)->content->first))
					insert(&(*node->right), key, val, *node);
				else
					return (make_pair(*node, false)); //ADD ITERATOR
			}
		}
	};  

	template <	class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = std::less<Key>,                     // map::key_compare
				class Allocator = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
	class map{
	public:
		typedef Key								 				key_type;
		typedef T								 				mapped_type;
		typedef ft::pair<const key_type, mapped_type> 			value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::pointer         		pointer;
		typedef typename allocator_type::const_pointer   		const_pointer;
		typedef typename allocator_type::size_type       		size_type;
		typedef typename allocator_type::difference_type 		difference_type;

		typedef ft::iterator<T>									iterator;
		typedef const ft::iterator<T>							const_iterator;
		typedef std::reverse_iterator<iterator>					reverse_iterator;
		typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;

	private:
		bst<key_type, T, Compare, Allocator>					_bst;
		key_compare												_comp;
		allocator_type											_alloc;
		size_type												_size;

	public :
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _bst(NULL){
		_bst(_alloc, _comp);
	}
	// template <class InputIterator>
	// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc){
	// 	_bst(_alloc, _comp);
	// }
	// map (const map& x){
	// 	_bst(_alloc, _comp);
	// }
	ft::pair<iterator,bool>	insert (const value_type& val){
		_bst.insert(_bst.getNode(), val.first, val.second, NULL);
	}
	iterator insert (iterator position, const value_type& val){
		_bst.insert(position, val.first, val.second, NULL);
	}
	// template <class InputIterator>
	// void insert (InputIterator first, InputIterator last){
	// 	while (first != last){
	// 		_bst.insert(_bst.getNode(), , );
	// 		first++;
	// 	}
	// }

	};
}
















#endif