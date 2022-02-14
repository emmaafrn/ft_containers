#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Iterator.hpp"
#include "ReverseIterator.hpp"
#include "utils.hpp"
#include <exception>
#include <memory>
#include <iostream>

namespace ft{

template<typename T, class Allocator = std::allocator<T> >
class	vector{

public:
typedef T																		value_type;
typedef Allocator																allocator_type;
typedef typename allocator_type::reference										reference;
typedef typename allocator_type::const_reference								const_reference;
typedef ptr_iterator<T>															iterator;
typedef ptr_iterator<const T>													const_iterator;
typedef typename allocator_type::size_type										size_type;
typedef typename allocator_type::difference_type								difference_type;
typedef typename allocator_type::pointer										pointer;
typedef typename allocator_type::const_pointer									const_pointer;
typedef ft::reverse_iterator<iterator>			reverse_iterator;
typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

private:
	Allocator	_alloc;
	value_type	*_tab;
	size_type	_size;
	size_type	_capacity;

public:
	explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tab(NULL), _size(0), _capacity(0){}
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n){
		size_type	i = 0;

		_tab = _alloc.allocate(_size);
		while (i < _size){
			_alloc.construct(&_tab[i], val);
			i++;
		}
	}
	template <class InputIterator>
	vector (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0){
		size_type	i = 0;
		
		for (size_type j = 0 ; j < size_type(last - first) ; j++){
			_size++;
		}
		_tab = _alloc.allocate(_size);
		while (i < _size){
			_alloc.construct(&_tab[i], *first);
			first++;
			i++;
		}
	}
	
	vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity){
		size_type i = 0;

		_tab = _alloc.allocate(_size);
		while (i < _size){
			_alloc.construct(&_tab[i], x._tab[i]);
			i++;
		}
	}

	~vector(){
		this->clear();
	}

	void	clear(){
		if (_size > 0){
			for (size_type i = _size - 1 ; i > 0; i--){
				_alloc.destroy(&_tab[i]);
			}
			_alloc.destroy(&_tab[0]);
		}
		if (_tab != NULL){
			_alloc.deallocate(_tab, _size);
			_tab = NULL;
		}
		_size = 0;
		_capacity = 0;
	}

	void	push_back(const value_type& val){
		value_type	*tmp;
		size_type	size_tmp = _size;
		size_type	capacity_tmp = (_capacity + 1) * 2;
		Allocator	alloc_tmp = _alloc;

		if (_size == _capacity){
			if (_size > 0)
				capacity_tmp = _capacity * 2;
			tmp = _alloc.allocate(capacity_tmp);
			for (size_type i = 0 ; i < _size ; i++) _alloc.construct(&(tmp[i]), _tab[i]);
			this->clear();
			_capacity = capacity_tmp;
			_alloc = alloc_tmp;
			_size = size_tmp;
			_tab = tmp;
		}
		_alloc.construct(&(_tab[_size]), val);
		(void)val;
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
		_tab = x._tab;
		x._tab = tmp;
		_size = x._size;
		x._size = size_tmp;
		_capacity = x._capacity;
		x._capacity = capacity_tmp;
		_alloc = x._alloc;
		x._alloc = alloc_tmp;
	}

	size_type size() const{
		return (_size);
	}

	size_type capacity() const{
		return (_capacity);
	}

	size_type max_size() const{
		return (_alloc.max_size());
	}

	bool empty() const{
		if (_size == 0)
			return (1);
		return (0);
	}

	vector& operator=(const vector& x){
		this->clear();
		_alloc = x._alloc;
		_tab = _alloc.allocate(x._size);
		for (size_type i = 0 ; i < x._size ; i++){
			_alloc.construct(&_tab[i], x._tab[i]);
		}
		_capacity = x._capacity;
		_size = x._size;
		return (*this);
	}

	reference	operator[](size_type n){
		return (_tab[n]);
	}

	const_reference	operator[](size_type n) const{
		return (_tab[n]);
	}

	iterator begin(){
		return (_tab);
	}

	iterator end(){
		return (&(_tab[_size]));
	}
	
	const_iterator begin() const{
		return (_tab);
	}

	const_iterator end() const{
		return (&(_tab[_size]));
	}
	reference at (size_type n){
		if (n >= _size)
			throw std::out_of_range("vector");
		return (_tab[n]);
	}
	const_reference at (size_type n) const{
		if (n >= _size)
			throw std::out_of_range("vector");
		return (&(_tab[n]));
	}
	reference front(){
		return (*_tab);
	}
	const_reference front() const{
		return (*_tab);
	}
	reference back(){
		return (_tab[_size - 1]);
	}
	const_reference back() const{
		return (_tab[_size - 1]);
	}
	void resize (size_type n, value_type val = value_type()){
		value_type	*tmp;
		size_type	i = 0;

		tmp = _alloc.allocate(n);
		for (; i < _size && i < n; i++) _alloc.construct(&tmp[i], _tab[i]);
		for (; i < n ; i++) _alloc.construct(&tmp[i], val);
		this->clear();
		_capacity = n;
		_size = n;
		_tab = tmp;
	}
	template <class InputIterator>
	void assign (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
		int i = 0;

		this->clear();
		_tab = _alloc.allocate(last - first);
		while (first != last){
			_alloc.construct(&_tab[i], *first);
			first++;
			i++;
		}
		_size = i;
		_capacity = i;
	}
	void assign (size_type n, const value_type& val){
		size_type	i = 0;
		
		this->clear();
		_tab = _alloc.allocate(n);
		while (i < n){
			_alloc.construct(&_tab[i], val);
			i++;
		}
		_size = i;
		_capacity = i;
	}
	void reserve (size_type n){
		value_type	*tmp;
		size_type	i = 0;
		size_type	s_tmp = _size;

		if (n > _capacity){
			tmp = _alloc.allocate(n);
			for (; i < _size ; i++) _alloc.construct(&tmp[i], _tab[i]);
			this->clear();
			_size = s_tmp;
			_capacity = n;
			_tab = tmp;
		}
	}
	reverse_iterator rbegin(){
		reverse_iterator it(end());
		return ++it;
	}
	const_reverse_iterator rbegin() const{
		const_reverse_iterator it(end());
		return ++it;
	}
	reverse_iterator rend(){
		reverse_iterator it(begin());
		return ++it;
	}
	const_reverse_iterator rend() const{
		const_reverse_iterator it(begin());
		return ++it;
	}
	iterator insert (iterator position, const value_type& val){
		insert(position, 1, val);
		return (begin());
	}
	void insert (iterator position, size_type n, const value_type& val){
		iterator	ite(end() - 1);
		iterator	it(begin());
		value_type	*ptr;
		size_type	i = 0;
		size_type	c = (_capacity + n) * 2;
		size_type	s = _size + n;

		if (_capacity >= _size + n){
			i = _size + n - 1;
			while (ite >= position){
				_alloc.construct(&_tab[i], *ite);
				ite--;
				_alloc.destroy(&_tab[i - n]);
				i--;
			}
			while (n > 0){
				_alloc.construct(&_tab[i], val);
				i--;
				n--;
			}
			_size = s;
		}
		else {
			ptr = _alloc.allocate(c);
			for (; it != position ; it++){ _alloc.construct(&ptr[i], *it); i++;};
			while (n > 0){
				_alloc.construct(&ptr[i], val);
				n--;
				i++;
			}
			while (it <= ite){
				_alloc.construct(&ptr[i], *it);
				it++;
				i++;
			}
			this->clear();
			_tab = ptr;
			_size = s;
			_capacity = c;
		}
	}
	template <class InputIterator>
	void insert (iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
		iterator	ite(end() - 1);
		iterator	it(begin());
		size_type	len = abs(first - last);
		value_type	*ptr;
		size_type	i = 0;

		if (_capacity >= _size + len){
			i = _size + len - 1;
			while (ite >= position){
				_alloc.construct(&_tab[i], *ite);
				ite--;
				_alloc.destroy(&_tab[i - len]);
				i--;
			}
			while (--last >= first){
				_alloc.construct(&_tab[i], *last);
				i--;
			}
			_size += len;
		}
		else {
			size_type	c = (_capacity + len) * 2;
			size_type	s = _size + len;

			ptr = _alloc.allocate(c);
			for (; it != position ; it++) {_alloc.construct(&ptr[i], *it); i++;};
			while (first != last){
				_alloc.construct(&ptr[i], *first);
				first++;
				i++;
			}
			while (it != ite){
				_alloc.construct(&ptr[i], *it);
				it++;
				i++;
			}
			this->clear();
			_tab = ptr;
			_size = s;
			_capacity = c;
		}
	}
	iterator erase (iterator position){
		iterator prev = position;

		while (prev != end() && position != end()){
			position++;
			if (position != end()){
				*prev = *position;
				prev++;
			}
		}
		_alloc.destroy(prev);
		_size--;
	}
	iterator erase (iterator first, iterator last){
		while (first != last){
			erase(first);
			first++;
		}
	}
};
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		typename vector<T>::size_type	i = 0;
		
		if (left.size() != right.size())
			return (0);
		while (i < right.size()){
			if (left[i] != right[i])
				return (0);
			i++;
		}
		return (1);
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		typename vector<T>::size_type	i = 0;

		if (left.size() != right.size())
			return (1);
		while (i < right.size()){
			if (left[i] != right[i])
				return (1);
			i++;
		}
		return (0);
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		if (lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()))
			return (1);
		return (0);
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		if (lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()))
			return (1);
		else if (!lexicographical_compare(right.begin(), right.end(), left.begin(), left.end())
			&& !lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()))
			return (1);
		return (0);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		if (lexicographical_compare(right.begin(), right.end(), left.begin(), left.end()))
			return (1);
		return (0);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& left, const vector<T, Alloc>& right){
		if (lexicographical_compare(right.begin(), right.end(), left.begin(), left.end()))
			return (1);
		else if (!lexicographical_compare(right.begin(), right.end(), left.begin(), left.end())
			&& !lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()))
			return (1);
		return (0);
	}
}

#endif