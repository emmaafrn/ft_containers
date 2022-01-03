#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map.hpp"
#include "pair.hpp"

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
			if (_node == rhs._node)
				return (1);
			return (0);
		}
		bool	operator!=(const iterator &rhs) const{
			if (_node != rhs._node)
				return (1);
			return (0);
		}
		reference	operator*(void) const{
			return (*_node);
		}
		pointer	operator->(void) const{
			return(_node);
		}
		
	};
	
	
}












#endif