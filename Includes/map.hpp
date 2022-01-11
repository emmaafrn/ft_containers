#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include "pair.hpp"
#include "map_iterator.hpp"

# define RED 0
# define BLACK 1
# define LEFT 0
# define RIGHT 1


namespace	ft{
	template<class T>
	struct Node{
		typedef		T		value_type;
		Node		*child[2];
		Node		*parent;
		value_type	*content;
		bool		color;
		bool		end;

		Node() : parent(NULL), content(NULL), color(BLACK), end(0){
			child[LEFT]->content = NULL;
			child[RIGHT]->content = NULL;
			child[RIGHT]->end = 1;
		}
		Node(Node &copy) : parent(copy->parent), content(copy->content), color(copy->color), end(0){
			child[LEFT] = copy->child[LEFT];
			child[RIGHT] = copy->child[RIGHT];
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
		node_ptr		_root;
		allocator_type	_alloc;
		key_compare		_comp;
		n_Allocator		n_alloc;
		size_type		_size;

	public:
		bst(allocator_type alloc, key_compare comp) : _root(NULL), _alloc(alloc), _comp(comp), n_alloc(), _size(0){}
		// template <class InputIterator>
		// bst(InputIterator first, InputIterator last){
			
		// }
		node	**getRoot(){
			return (&_root);
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
			if (node == parent->child[LEFT])
				return (parent->child[RIGHT]);
			return (parent->child[LEFT]);
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
		void	insertion_repare(node_ptr node){
			node_ptr	parent = get_parent(node);
			
			if (parent == NULL)
				insertion_case1(node);
			else if (parent && parent->color == RED)
				insertion_case2(node);
			else if (parent && get_uncle(node) && get_uncle(node)->color == BLACK)
				insertion_case3(node);
			else
				insertion_case4(node);

		}
		void	insertion_case1(node_ptr node){ // si le noeud inséré est à la racine
			// std::cout << "CASE 1\n";
			node->color = BLACK;
		}
		void	insertion_case2(node_ptr node){ // si le parent du noeud inséré est rouge
			// std::cout << "CASE 2\n";
			get_parent(node)->color = BLACK;
			get_uncle(node)->color = BLACK;

			node_ptr gp;
			gp = get_grand_parent(node);
			gp->color = RED;
			insertion_repare(gp);
		}
		void	insertion_case3(node_ptr node){ // si l'oncle est noir
			// std::cout << "CASE 3\n";
			node_ptr	p = get_parent(node);
			node_ptr	gp = get_grand_parent(node);

			if (node == gp->child[LEFT]->child[RIGHT]) {
				rotate(p, LEFT);
				node = node->child[LEFT];
			}
			else if (node == gp->child[RIGHT]->child[LEFT]) {
				rotate(p, RIGHT);
				node = node->child[RIGHT]; 
			}
			insertion_case4(node);
		}
		void	insertion_case4(node_ptr node){ // Le parent vient prendre la place du grand-parent, et le grand-parent celle de l'oncle.
												// Le parent devient noir et le grand-parent rouge
				// std::cout << "CASE 4\n";
				node_ptr	p = get_parent(node);
				node_ptr	gp = get_grand_parent(node);

				if (p == NULL || gp == NULL)
					return ;
				if (node == p->child[LEFT])
					rotate(gp, RIGHT);
				else
					rotate(gp, LEFT);
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
				(*node)->child[LEFT]->content = NULL;
				(*node)->child[RIGHT]->content = NULL;
				if ((*node)->end){
					(*node)->end = 0;
					(*node)->child[RIGHT]->end = 0;
				}
				_size++;
				insertion_repare(*node);
				return (make_pair(iterator(*node), true));
			}
			else {
				if (_comp((*node)->content->first, key))
					return insert((&((*node)->child[LEFT])), key, val, *node);
				else if (_comp(key, (*node)->content->first))
					return insert(&(((*node)->child[RIGHT])), key, val, *node);
				else
					return (make_pair(iterator(*node), false));
			}
		}
		const_iterator find (const key_type& k) const{
			node_ptr	tmp = _root;

			while (tmp){
				if (_comp(tmp->content->first, k))
					tmp = tmp->child[RIGHT];
				else if (_comp(k, tmp->content->first))
					tmp = tmp->child[LEFT];
				else
					return (const_iterator(tmp->content));
			}
			return (end());
		}
		iterator find (const key_type& k){
			node_ptr	tmp = _root;

			while (tmp){
				if (_comp(tmp->content->first, k))
					tmp = tmp->child[RIGHT];
				else if (_comp(k, tmp->content->first))
					tmp = tmp->child[LEFT];
				else
					return (iterator(tmp->content));
			}
			return (end());
		}
		iterator begin(){
			node_ptr begin = _root;

			while (begin && begin->child[LEFT])
				begin = begin->child[LEFT];
			return (iterator(begin->content));
		}
		const_iterator begin() const{
			node_ptr begin = _root;

			while (begin && begin->child[LEFT])
				begin = begin->child[LEFT];
			return (const_iterator(begin->content));
		}
		iterator end(){
			node_ptr end = _root;

			while (end && end->child[RIGHT])
				end = end->child[RIGHT];
			return (iterator(end))
		}
		const_iterator end() const{

		}
		bool empty() const{
			if (!_root->content && !_root->child[LEFT] && !_root->child[RIGHT])
				return (1);
			return (0);
		}
	};

		template <	class Key,                                     // map::key_type
					class T,                                       // map::mapped_type
					class Compare = std::less<Key>,                     // map::key_compare
					class Allocator = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
	class map{
	public:
		typedef Key								 											key_type;
		typedef T								 											mapped_type;
		typedef ft::pair<const key_type, mapped_type> 										value_type;
		typedef Compare																		key_compare;
		typedef Allocator																	allocator_type;
		typedef typename allocator_type::reference											reference;
		typedef typename allocator_type::const_reference 									const_reference;
		typedef typename allocator_type::pointer         									pointer;
		typedef typename allocator_type::const_pointer   									const_pointer;
		typedef typename allocator_type::size_type       									size_type;
		typedef typename allocator_type::difference_type 									difference_type;

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
			return (_bst.insert(_bst.getRoot(), val.first, val.second, NULL));
		}
		iterator insert (iterator position, const value_type& val){
			return (_bst.insert(position, val.first, val.second, NULL).first);
		}
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last){
		// }
		iterator begin(){
			return (_bst.begin());
		}
		const_iterator begin() const{
			return (_bst.begin());
		}
		iterator end(){
			return (_bst.end());
		}
		const_iterator end() const{
			return (_bst.end());
		}
		bool empty() const{
			return (_bst.empty());
		}
		size_type size() const{
			return (_size);
		}
		size_type max_size() const{
			return (_alloc.max_size());
		}
		iterator find (const key_type& k){
			return (_bst.find(k));
		}
		const_iterator find (const key_type& k) const{
			return (_bst.find(k));
		}
		// mapped_type& operator[] (const key_type& k){
		// 	iterator	it = find(k);
	
		// 	if (it != end())
		// 		return (it->_node->content->second_type);
		// 	insert(make_pair(k, mapped_type()));
		// }
		// void swap (map& x){

		// }
		// void clear(){

		// }
		// key_compare key_comp() const{

		// }
		// value_compare value_comp() const{

		// }
		// void erase (iterator position){

		// }
		// size_type erase (const key_type& k){

		// }
		// void erase (iterator first, iterator last){

		// }
	};
}
















#endif
