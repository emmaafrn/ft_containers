#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

struct random_access_iterator_tag
{
	
};

template<class T>
class random_access_iterator : iterator<random_access_iterator_tag, T>{
private:
	typename random_access_iterator::pointer	_ptr;
public:
	random_access_iterator(void){
		_ptr = NULL;
	}
	random_access_iterator(const random_access_iterator &copy){
		_ptr = copy._ptr;
	}
	~random_access_iterator(){
		
	}
	random_access_iterator	&operator++(void){
		_ptr++;
		return (*this);
	}
	random_access_iterator	operator++(int){
		random_access_iterator	prev = *this;

		_ptr++;
		return (prev);
	}
	random_access_iterator	&operator--(void){
		_ptr--;
		return (*this);
	}
	random_access_iterator	operator--(int){
		random_access_iterator	prev = *this;

		_ptr--;
		return (prev);
	}
	random_access_iterator	&operator-(const random_access_iterator &rhs){
		_ptr -= rhs._ptr;
		return (*this);
	}
	random_access_iterator	&operator+(int x){
		_ptr += x;
		return (*this);
	}
	random_access_iterator	&operator-(int x){
		_ptr -= x;
		return (*this);
	}
	random_access_iterator	&operator+=(int x){
		_ptr += x;
		return (*this);
	}
	random_access_iterator	&operator-=(int x){
		_ptr -= x;
		return (*this);
	}
	random_access_iterator	&operator=(const random_access_iterator &rhs){
		_ptr = rhs._ptr;
		return (*this);
	}
	T*	&operator*(void){
		return (_ptr);
	}
	template<typename A, typename B>
	friend bool	operator==(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr == rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator!=(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr != rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator<(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr < rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator>(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr > rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator<=(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr <= rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator>=(random_access_iterator<A> lhs, random_access_iterator<B> rhs){
		if (lhs._ptr >= rhs._ptr)
			return (1);
		return (0);
	}
};


#endif