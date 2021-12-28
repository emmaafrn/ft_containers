#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map.hpp"
#include "pair.hpp"

namespace	ft{
	template <class T>
	class iterator{
		public :
		typedef typename	T::value_type		value_type;
		typedef				T*					pointer;
		typedef				T&					reference;
		private :
		pointer		_node;
		public :
		iterator() : _node(NULL){};
		iterator(const iterator &copy) : _node(copy._node){};
		void	operator=(const iterator &rhs){
			_node = rhs._node;
		}
		bool	operator==(const iterator &rhs){
			if (_node == rhs._node)
				return (1);
			return (0);
		}
		bool	operator!=(const iterator &rhs){
			if (_node != rhs._node)
				return (1);
			return (0);
		}
		reference	operator*(void){
			return (*_node);
		}
		pointer	*operator->(void){
			return(_node);
		}
		
	};
}












#endif