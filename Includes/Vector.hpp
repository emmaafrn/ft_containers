#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Iterator.hpp"
#include <memory>

template<typename T, class Allocator = std::allocator<T> >
class	vector{

public:
typedef T											value_type;
typedef Allocator									allocator_type;
typedef typename allocator_type::reference			reference;
typedef typename allocator_type::const_reference	const_reference;
// typedef implementation-defined						iterator;
// typedef implementation-defined						const_iterator;
typedef typename allocator_type::size_type			size_type;
// typedef typename allocator_type::difference_type	difference_type;
// typedef typename allocator_type::pointer			pointer;
// typedef typename allocator_type::const_pointer		const_pointer;
// typedef std::reverse_iterator<iterator>				reverse_iterator;
// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

private:
	Allocator	_alloc;
	value_type	*_tab;
	size_type	_size;
	size_type	_capacity;
public:
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _tab(NULL), _alloc(alloc), _capacity(0){}
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc), _capacity(_size){
		size_type	i = 0;

		_tab = _alloc.allocate(_size);
		while (i < _size){
			_alloc.construct(&tab[i], val);
			i++;
		}
	}
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc){

	}
	vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity){
		size_type i = 0;

		_tab = _alloc.allocate(_size);
		while (i < _size){
			_alloc.construct(&tab[i], x._tab[i]);
			i++;
		}
	}

	void	clear(){
		if (_capacity > 0){
			for (size_type i = _capacity - 1 ; i > 0; i--){
				_alloc.destroy(&_tab[i]);
				&tab[i] = NULL;
			}
		}
		_alloc.deallocate(_tab);
		_tab = NULL;
		_alloc = NULL;
		_size = NULL;
		_capacity = NULL;
	}

	void	push_back(const value_type& val){
		value_type	*tmp;
		size_type	size_tmp = _size;
		size_type	capacity_tmp = _capacity;
		Allocator	alloc_tmp = _alloc;

		if (_size == _capacity){
			tmp = alloc.allocate(_size * 2);
			for (size_type i = 0 ; i < _size ; i++){
				_alloc.construct(&tmp[i], _tab[i]);
			}
			*this->clear();
			_capacity = capacity_tmp * 2;
			_alloc = alloc_tmp;
			_size = size_tmp;
			_capacity = capacity_tmp;
			_tab = tmp;
		}
		_tab[_size] = val;
		_size++;
	}

	void	pop_back(){
		if (_size < 1)
			return ;
		_alloc.destroy(&_tab[_size - 1]);
		_size--;
	}

	void	swap (vector& x){
		value_type	*tmp;
		size_type	size_tmp = _size;
		size_type	capacity_tmp = _capacity;
		Allocator	alloc_tmp = _alloc;

		tmp = _tab;
		_tab = x->_tab;
		x->_tab = tmp;
		
	}

	size_type size() const{
		return (_size);
	}
	size_type capacity() const{
		return (_capacity);
	}
	bool empty() const{
		if (_size == 0)
			return (1);
		return (0);
	}
	vector& operator= (const vector& x){
		*this->clear();
		_alloc = x->_alloc;
		_tab = _alloc.allocate(x->_size);
		for (size_type i = 0 ; i < x->_size ; i++){
			_alloc.construct(&tab[i], x->_tab[i]);
		}
		_capacity = x->_capacity;
		_size = x->_size;
	}


};





#endif



