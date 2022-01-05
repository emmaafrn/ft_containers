#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include "pair.hpp"
#include "map_iterator.hpp"

# define RED 0
# define BLACK 1


namespace	ft{
	template<class T>
	struct Node{
		typedef		T		value_type;
		Node		*child[2];
		Node		*parent;
		value_type	*content;
		bool		color;

		Node() : child{NULL, NULL}, parent(NULL), content(NULL), color(BLACK){}
		Node(Node &copy) : child{copy->child[0], copy->child[1]}, parent(copy->parent), content(copy->content), color(copy->color){}
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
	typedef	Node<value_type>									node;
	typedef	node*												node_ptr;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference 			const_reference;
	typedef typename allocator_type::pointer         			pointer;
	typedef typename allocator_type::const_pointer   			const_pointer;
	typedef typename allocator_type::size_type       			size_type;
	typedef typename allocator_type::difference_type 			difference_type;
	typedef ft::iterator<node>									iterator;
	typedef const ft::iterator<node>							const_iterator;
	typedef std::reverse_iterator<iterator>						reverse_iterator;
	typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename Allocator::template rebind<node>::other	n_Allocator;

	private:
		node_ptr		_node;
		allocator_type	_alloc;
		key_compare		_comp;
		n_Allocator		n_alloc;

	public:
		bst(allocator_type alloc, key_compare comp) : _node(NULL), _alloc(alloc), _comp(comp), n_alloc(){}
		// template <class InputIterator>
		// bst(InputIterator first, InputIterator last){
			
		// }
		node	**getNode(){
			return (&_node);
		}

		node_ptr	get_grand_parent(node_ptr node){
			if (get_parent(node) == NULL)
				return (NULL);
			return (node->parent->parent);
		}

		node_ptr	get_parent(node_ptr node){
			return (node->parent);
		}

		node_ptr	get_uncle(node_ptr node){
			if (get_grand_parent(node) == NULL)
				return (NULL);
			return (get_brother(get_parent(node)));
		}

		node_ptr	get_brother(node_ptr node){
			node_ptr parent = get_parent(node);

			if (parent == NULL)
				return (NULL);
			if (node == parent->child[0])
				return (parent->child[1]);
			return (parent->child[0]);
		}

		node_ptr	rotate(node *root, int dir){
			node	*pivot;
			node	*tmp;
			
			pivot = root->child[1 - dir];
			root->child[1 - dir] = pivot->child[dir];
			pivot->child[dir] = root;
			tmp = root->parent;
			root->parent = pivot;
			pivot->parent = tmp;
			return (pivot);
		}

		void	insertion_case1(node_ptr node){ // si le noeud inséré est à la racine
			if (get_parent(node) == NULL)
				node->color = BLACK;
		}
		void	insertion_case2(node_ptr node){ // si le parent du noeud inséré est rouge
			get_parent(node)->color = BLACK;
			get_uncle(node)->color = BLACK;

			node_ptr gp;
			gp = get_grand_parent(node);
			gp->color = RED;
			// PUIS RE CHECKER SI BESOIN DE REPARATIONS A PARTIR DE GP CETTE FOIS_CI
		}
		void	insertion_case3(node_ptr node){ // si l'oncle est noir
			node_ptr	p = get_parent(node);
			node_ptr	gp = get_grand_parent(node);

			if (node == gp->child[0]->child[1]) {
				rotation(p, 0);
				node = node->child[0];
			}
			else if (node == gp->child[1]->child[0]) {
				rotation(p, 1);
				node = node->child[1]; 
			}
			insertion_case4(node);
		}
		void	insertion_case4(node_ptr node){ // Le parent vient prendre la place du grand-parent, et le grand-parent celle de l'oncle.
												// Le parent devient noir et le grand-parent rouge
				struct noeud *p = parent(node);
				struct noeud *gp = grandparent(node);

				if (node == p->child[0])
					rotate(gp, 1);
				else
					rotate(gp, 0);
				p->color = BLACK;
				gp->color = RED;
		}

		ft::pair<iterator,bool> insert(node **node, key_type key, mapped_type val, node_ptr previous){
			if (*node == NULL){
				*node = n_alloc.allocate(1);
				n_alloc.construct(*node); // ADD NODE'S CONSTRUCT
				(*node)->content = _alloc.allocate(1);
				_alloc.construct((*node)->content, make_pair(key, val)); // PAIR'S CONSTRUCT
				(*node)->parent = previous;
				(*node)->color = RED;
				return (make_pair(iterator(*node), true));
			}
			else {
				if (_comp((*node)->content->first, key))
					return insert((&((*node)->child[0])), key, val, *node);
				else if (_comp(key, (*node)->content->first))
					return insert(&(((*node)->child[1])), key, val, *node);
				else
					return (make_pair(iterator(*node), false)); //ADD ITERATOR
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

		typedef ft::iterator<typename bst<key_type, T, Compare, Allocator>::node>			iterator;
		typedef ft::iterator<const typename bst<key_type, T, Compare, Allocator>::node>		const_iterator;
		typedef std::reverse_iterator<iterator>												reverse_iterator;
		typedef std::reverse_iterator<const_iterator>										const_reverse_iterator;

	private:
		bst<key_type, T, Compare, Allocator>					_bst;
		key_compare												_comp;
		allocator_type											_alloc;
		size_type												_size;

	public :
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
		: _bst(alloc, comp)
		, _comp(comp)
		, _alloc(alloc)
	{}

	// template <class InputIterator>
	// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc){
	// 	_bst(_alloc, _comp);
	// }
	// map (const map& x){
	// 	_bst(_alloc, _comp);
	// }
	ft::pair<iterator,bool>	insert (const value_type& val){
		return (_bst.insert(_bst.getNode(), val.first, val.second, NULL));
	}
	iterator insert (iterator position, const value_type& val){
		return (_bst.insert(position, val.first, val.second, NULL).first);
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
