#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map.hpp"
#include "pair.hpp"

# define LEFT 0
# define RIGHT 1

namespace	ft{
	template <class T>
	class iterator{
		public :
		typedef 				T					node;
		typedef		typename	T::value_type*		pointer;
		typedef		typename	T::value_type&		reference;
		private :
		node		*_node;
		public :
		iterator() : _node(NULL){};
		iterator(node *node) : _node(node){};
		iterator(const iterator &copy) : _node(copy._node){};
		void	operator=(const iterator &rhs){
			_node = rhs._node;
		}
		bool	operator==(const iterator &rhs) const{
			return (_node == rhs._node);
		}
		bool	operator!=(const iterator &rhs) const{
			return (_node != rhs._node);
		}
		reference	operator*(void) const{
			return (*_node);
		}
		pointer	operator->(void) const{
			return (_node);
		}
		iterator&	operator++(void) const{
			if (_node->child[RIGHT]){
				_node = _node->child[RIGHT];
				while (_node->child[LEFT]){
					_node = _node->child[LEFT];
				}
			}
			else {
				while (_node->parent && _node->parent->child[RIGHT] == _node){
					_node = _node->parent;
				}
				_node = _node->parent;
			}
			return (iterator(_node));
		}
	};
}












#endif