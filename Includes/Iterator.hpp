#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft{

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	public :
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
class random_access_iterator : public iterator<random_access_iterator_tag, T>{
	public :
	typedef typename random_access_iterator::pointer pointer;
private:
	pointer	_ptr;
public:
	random_access_iterator(void){
		_ptr = NULL;
	}
	random_access_iterator(const random_access_iterator &copy){
		_ptr = copy._ptr;
	}
	random_access_iterator(const pointer non){
		_ptr = non;
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
	friend int	operator-(const random_access_iterator &lhs, const random_access_iterator &rhs){
	int res = lhs._ptr - rhs._ptr;
		return (res);
	}
	friend random_access_iterator	operator+(const random_access_iterator &lhs, int x){
		random_access_iterator	it;

		it._ptr = lhs._ptr + x;
		return (it);
	}
	friend random_access_iterator	operator-(const random_access_iterator &lhs, int x){
		random_access_iterator	it;

		it._ptr = lhs._ptr - x;
		return (it);
	}
	void	operator+=(int x){
		_ptr += x;
	}
	void	operator-=(int x){
		_ptr -= x;
	}
	random_access_iterator	&operator=(const random_access_iterator &rhs){
		_ptr = rhs._ptr;
		return (*this);
	}
	T	&operator*(void){
		return (*_ptr);
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

}

#endif