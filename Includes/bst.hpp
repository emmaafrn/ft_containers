#ifndef BST_HPP
#define BST_HPP

#include "ReverseIterator.hpp"
#include "bst_iterator.hpp"
#include "bst_node.hpp"
#include "pair.hpp"
#include <cstddef>
#include <iostream>
#include <map>

#define RED 0
#define BLACK 1
#define RIGHT 1
#define LEFT 0


namespace ft {

template <class T, class key, class mapped, class Compare, class Alloc> class bst {
public:
	typedef T value_type;
	typedef ft::bst_node<value_type> Node;
	typedef Node *node_pointer;
	typedef mapped mapped_type;
	typedef bst_iterator<Node, value_type, mapped_type> iterator;
	typedef bst_iterator<Node, const value_type, mapped_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef Alloc allocator_type;
	typedef size_t size_type;
	typedef key key_type;
	typedef Compare key_compare;

public:
	bst(allocator_type alloc = allocator_type(), key_compare comp = key_compare())
			: _alloc(alloc), _comp(comp), _root(), _size(0), _last(NULL) {
		_begin_node = _alloc.allocate(1);
		_alloc.construct(_begin_node, value_type());
		_end_node = _alloc.allocate(1);
		_alloc.construct(_end_node, value_type());
	}
	private :
	node_pointer	_tree_copy(node_pointer to_copy, node_pointer copy_begin, node_pointer copy_end, node_pointer parent){
		node_pointer n;
		
		n = _alloc.allocate(1);
		_alloc.construct(n, to_copy->value);
		n->p = parent;
		_size++;
		if (to_copy->l && to_copy->l != copy_begin)
			n->l = _tree_copy(to_copy->l, copy_begin, copy_end, n);
		if (to_copy->r && to_copy->r != copy_end)
			n->r = _tree_copy(to_copy->r, copy_begin, copy_end, n);
		return n;
	}
	public :
	bst(const bst &copy) : _alloc(copy._alloc), _comp(copy._comp), _root(NULL), _size(0){
		_begin_node = _alloc.allocate(1);
		_alloc.construct(_begin_node, Node(value_type()));
		_end_node = _alloc.allocate(1);
		_alloc.construct(_end_node, Node(value_type()));
		if (copy._root)
			_root = _tree_copy(copy._root, copy._begin_node, copy._end_node, NULL);
		assign_limit();
		_last = copy._last;
	}
	~bst() {
		clear();
		if (_begin_node){
			_alloc.destroy(_begin_node);
			_alloc.deallocate(_begin_node, 1);
		}
		if (_end_node){
			_alloc.destroy(_end_node);
			_alloc.deallocate(_end_node, 1);
		}
	}
	void	destruct(node_pointer node){
		node_pointer left = node->l;
		node_pointer right = node->r;

		if (node != _begin_node && node != _end_node){
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
		if (left && left !=_begin_node)
			destruct(left);
		if (right && right != _end_node)
			destruct(right);
	}
	ft::pair<iterator, bool> insert(const value_type &val) {
		destroy_limit();
		ft::pair<node_pointer, bool> tmp = _insert(_root, NULL, 0, val);
		if (_last)
			insertion_repare(_last);
		assign_limit();
		if (tmp.second)
			_size++;
		return ft::make_pair(iterator(tmp.first), tmp.second);
	}
	private:
	ft::pair<node_pointer, bool> _insert(node_pointer node, node_pointer prev, bool dir, const value_type &val) {
		ft::pair<node_pointer, bool> ret(NULL, false);
		if (!node) {
			if (!_root) {
				_root = _alloc.allocate(1);
				_alloc.construct(_root, Node(val));
				return ft::make_pair(_root, true);
			} else {
				node = _alloc.allocate(1);
				_alloc.construct(node, Node(val));
				_last = node;
				if (dir == LEFT)
					prev->l = node;
				else
				 	prev->r = node;
				node->p = prev;
				return ft::make_pair(node, true);
			}
		}
		else if (_comp(node->value.first, val.first))
			ret = _insert(node->r, node, RIGHT, val);
		else if (_comp(val.first, node->value.first))
			ret = _insert(node->l, node, LEFT, val);
		else
			ret = ft::make_pair(node, false);
		return ret;
	}

	public:
	iterator find(const key_type &k) {
		iterator tmp = _find(_root, k, end());

		return tmp;
	}
	const_iterator find(const key_type &k) const{
		const_iterator tmp = _find(_root, k, end());

		return tmp;
	}

	private:
	iterator _find(node_pointer node, const key_type &k, iterator tmp){
		static bool	found = false;
		if (node && _comp(k, node->value.first)) {
			tmp = _find(node->l, k, tmp);
		} else if (node && _comp(node->value.first, k)) {
			tmp = _find(node->r, k, tmp);
		}
		else if (node) {
			found = true;
			tmp = iterator(node);
			return tmp;
		}
		if (found)
			return tmp;
		return end();
	}
	const_iterator _find(node_pointer node, const key_type &k, const_iterator tmp) const{
		static bool	found = false;
		
		if (node && _comp(k, node->value.first)) {
			tmp = _find(node->l, k, tmp);
		} else if (node && _comp(node->value.first, k)) {
			tmp = _find(node->r, k, tmp);
		}
		else if (node) {
			found = true;
			tmp = const_iterator(node);
			return tmp;
		}
		if (found)
			return tmp;
		return end();
	}
	void destroy_limit(void){
		if (_begin_node && _root && _begin_node->p)
			_begin_node->p->l = NULL;
		if (_end_node && _root && _end_node->p)
			_end_node->p->r = NULL;
	}
	void assign_limit(void) {
		if (_root) {
			node_pointer tmp = _root;
			while (tmp->l)
				tmp = tmp->l;
			tmp->l = _begin_node;
			_begin_node->p = tmp;

			tmp = _root;
			while (tmp->r)
				tmp = tmp->r;
			tmp->r = _end_node;
			_end_node->p = tmp;
		}
		else {
			_root = _begin_node;
			_begin_node->r = _end_node;
			_end_node->p = _begin_node;
			_begin_node->p = _root;
		}
	}

	public :
	void erase(iterator pos) {
		destroy_limit();
		_root = _erase(_root, pos.base()->value);
		_size--;
		assign_limit();
	}

	private:
	node_pointer   _find_successor(node_pointer node, node_pointer deleted){
		if (node->l)
			node = _find_successor(node->l, deleted);
		else {
			node->l = deleted->l;
			if (deleted->l)
				deleted->l->p = node;
			if (node != deleted->r){
				node->r = deleted->r;
				node->r->p = node;
				if (node->r && node == node->r->l)
					node->r->l = NULL;
			}
			node->p = deleted->p;
			if (deleted != _root && deleted == deleted->p->l)
				node->p->l = node;
			else if (deleted != _root && deleted == deleted->p->r)
				node->p->r = node;
			node->color = deleted->color;
			_alloc.destroy(deleted);
			_alloc.deallocate(deleted, 1);
		}
		return node;
	}
	node_pointer _has_child(node_pointer node){
		if (node->r){
			node = _find_successor(node->r, node);
		}
		else {
			node_pointer left = node->l;

			node->l->p = node->p;
			if (node->p && node == node->p->r)
				node->p->r = node->l;
			else if (node->p)
				node->p->l = node->l;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			return left;
		}
		return node;
	}
	node_pointer _erase(node_pointer node, value_type val) {
		if (node && node->value.first == val.first) {
			if (!node->l && !node->r){
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				return NULL;
			}
			else
				return _has_child(node);
		} else if (node && _comp(val.first, node->value.first)) {
			node->l = _erase(node->l, val);
			if (node->l)
				node->l->p = node;
		} else if (node && _comp(node->value.first, val.first)) {
			node->r = _erase(node->r, val);
			if (node->r)
				node->r->p = node;
		}
		return (node);
	}

	public:
	iterator begin() {
		if (_size == 0)
			return end();
		return ++iterator(_begin_node);
	}
	const_iterator begin() const {
		if (_size == 0)
			return end();
		return ++const_iterator(_begin_node);
	}
	iterator end() { return iterator(_end_node); }
	const_iterator end() const { return const_iterator(_end_node); }
	reverse_iterator rend() { return reverse_iterator(_begin_node); }
	reverse_iterator rbegin() { return ++reverse_iterator(_end_node); }
	const_reverse_iterator rend() const { return const_reverse_iterator(_begin_node); }
	const_reverse_iterator rbegin() const { return ++const_reverse_iterator(_end_node); }
	size_type size() const { return _size; }
	size_type max_size() const { return _alloc.max_size(); }
	bool empty() const{
		if (_size > 0)
			return (false);
		return (true);
	}
	key_compare key_comp() const{
		return _comp;
	}
	iterator lower_bound (const key_type& k){
		node_pointer	tmp = _root;
		node_pointer	res = tmp;

		while (tmp){
			if (!_comp(tmp->value.first, k))
				tmp = tmp->l;
			else
				tmp = tmp->r;
			if (tmp && !_comp(tmp->value.first, k))
				res = tmp;
		}
		return iterator(res);
	}
	iterator upper_bound (const key_type& k){
		node_pointer	tmp = _root;
		node_pointer	res = tmp;

		while (tmp){
			if (!_comp(tmp->value.first, k) && !(!_comp(tmp->value.first, k) && !_comp(k, tmp->value.first)))
				tmp = tmp->l;
			else
				tmp = tmp->r;
			if (tmp && !_comp(tmp->value.first, k) && !(!_comp(tmp->value.first, k) && !_comp(k, tmp->value.first)) )
				res = tmp;
		}
		return iterator(res);
	}
	pair<iterator,iterator> equal_range (const key_type& k){
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	void clear(){
		if (_root){
			destruct(_root);
			_root = NULL;
			_size = 0;
			destroy_limit();
		}
	}
	mapped_type& operator[] (const key_type& k){
		insert(ft::make_pair(k, mapped_type()));
		return find(k)->second;
	}
	private: 
	allocator_type  _alloc;
	key_compare     _comp;
	node_pointer    _root;
	node_pointer    _begin_node;
	node_pointer    _end_node;
	size_type       _size;
	node_pointer    _last;

	node_pointer	get_grand_parent(node_pointer node){
		node_pointer gparent = get_parent(get_parent(node));
		if (gparent == NULL)
			return (NULL);
		return (gparent);
	}
	node_pointer	get_parent(node_pointer node){
		if (node && node->p != _begin_node && node->p != _end_node)
			return (node->p);
		return (NULL);
	}
	node_pointer	get_uncle(node_pointer node){
		if (get_grand_parent(node) == NULL)
			return (NULL);
		return (get_brother(get_parent(node)));
	}
	node_pointer	get_brother(node_pointer node){
		node_pointer parent = get_parent(node);

		if (parent == NULL)
			return (NULL);
		if (node == parent->l)
			return (parent->r);
		return (parent->l);
	}
	void left_rotation(node_pointer root) {
		node_pointer pivot = root->r;

		root->r = pivot->l; //le fils r de root devient le fils gauche de pivot
		if (pivot->l /*&& (pivot->l->r || pivot->l->l)*/)
			pivot->l->p = root;
		pivot->p = root->p;
		if (root->p == NULL){ //Si root est la racine, pivot devient la racine
			_root = pivot;
			pivot->p = NULL;
		}
		else if (root == root->p->l) //Sinon, on remplace root par pivot
			root->p->l = pivot;
		else if (root == root->p->r)
			root->p->r = pivot;
		pivot->l = root; //On attache root à gauche de pivot
		root->p = pivot;
	}
	void right_rotation(node_pointer root) {
		node_pointer pivot = root->l;


		root->l = pivot->r; //le fils l de root devient le fils droit de pivot
		if (pivot->r /*&& (pivot->r->r || pivot->r->l)*/)
			pivot->r->p = root;
		pivot->p = root->p;
		if (root->p == NULL){ //Si root est la racine, pivot devient la racine
			_root = pivot;
			pivot->p = NULL;
		}
		else if (root == root->p->r) // Sinon, on remplace root par pivot
			root->p->r = pivot;
		else if (root == root->p->l)
			root->p->l = pivot;
		pivot->r = root; //On attache root à droite de pivot
		root->p = pivot;
	}
	void	insertion_repare(node_pointer node){
		node_pointer	parent = get_parent(node);
		
		if (parent == NULL)
			insertion_case1(node);
		else if (parent && parent->color == BLACK)
			return ;
		else if (parent && get_uncle(node) && get_uncle(node)->color == RED)
			insertion_case2(node);
		else if (node)
			insertion_case3(node);

	}
	void	insertion_case1(node_pointer node){ // si le noeud inséré est à la racine
		node->color = BLACK;
	}
	void	insertion_case2(node_pointer node){ // si le parent du noeud inséré est rouge
		get_parent(node)->color = BLACK;
		node_pointer  uncle = get_uncle(node);
		node_pointer  gp;

		if (uncle)
			uncle->color = BLACK;
		gp = get_grand_parent(node);
		if (gp){
			gp->color = RED;
			insertion_repare(gp);
		}
	}
	void	insertion_case3(node_pointer node){ // si l'oncle est noir
		node_pointer	p = get_parent(node);
		node_pointer	gp = get_grand_parent(node);

		if (gp && gp->l && node == gp->l->r) {
			left_rotation(p);
			node = node->l;
		}
		else if (gp && gp->r && node == gp->r->l) {
			right_rotation(p);
			node = node->r; 
		}
		insertion_case4(node);
	}
	void	insertion_case4(node_pointer node){ // Le parent vient prendre la place du grand-parent, et le grand-parent celle de l'oncle.
												// Le parent devient noir et le grand-parent rouge

		node_pointer	p = get_parent(node);
		node_pointer	gp = get_grand_parent(node);

		if (p == NULL || gp == NULL)
			return ;
		if (node == p->l)
			right_rotation(gp);
		else if (node == p->r)
			left_rotation(gp);
		p->color = BLACK;
		gp->color = RED;
	}
	public :
	// TREE PRINTER
	void    ft_printNode(node_pointer tmp, int level, int levelMax) const{
		if (levelMax != 0 && level == levelMax)
			return;
		if (tmp)
		{
			ft_printNode(tmp->r, level + 1, levelMax);
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			if (tmp->color == 0)
				std::cout << "R : " << "{" << tmp->value.first << ", " << tmp->value.second << "}" << std::endl;
			else
				std::cout << "B : " << "{" << tmp->value.first << ", " << tmp->value.second << "}" << std::endl;
			ft_printNode(tmp->l, level + 1, levelMax);
		}
		else
		{
			if (levelMax != 0)
				ft_printNode(NULL, level + 1, levelMax);
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			std::cout << "B : ..." << std::endl;
			if (levelMax != 0)
				ft_printNode(NULL, level + 1, levelMax);
		}
	}
	void    ft_printTree(int levelMax = 0) const{
		std::cout << " -- MyTree -- " << std::endl;
		ft_printNode(this->_root, 0, levelMax);
		std::cout << " -- END -- " << std::endl;
	}
	//
};
}

#endif