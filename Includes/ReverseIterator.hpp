#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <cstddef>
#include "Iterator.hpp"

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct reverseiterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

struct rev_random_access_iterator_tag
{
	
};

template<class T>
class rev_random_access_iterator : reverseiterator<rev_random_access_iterator_tag, T>{
private:
	typename random_access_iterator it;
public:
	rev_random_access_iterator(){
		it.random_access_iterator();
	}
	rev_random_access_iterator(const rev_random_access_iterator &copy){
		it.random_access_iterator(copy);
	}
	~rev_random_access_iterator(){
		it.~random_access_iterator();
	}
	rev_random_access_iterator	&operator++(void){
		it--;
		return (*this);
	}
	rev_random_access_iterator	operator++(int){
		rev_random_access_iterator prev = this;

		--it;
		return (prev);
	}
	rev_random_access_iterator	&operator--(void){
		it++;
		return (*this);
	}
	rev_random_access_iterator	operator--(int){
		rev_random_access_iterator prev = this;

		++it;
		return (prev);
	}
	rev_random_access_iterator	&operator-(const rev_random_access_iterator &rhs){
		it = it + rhs.it;
		return (*this);
	}
	rev_random_access_iterator	&operator+(int x){
		it = it - x;
		return (*this);
	}
	rev_random_access_iterator	&operator-(int x){
		it = it + x;
		return (*this);
	}
	rev_random_access_iterator	&operator+=(int x){
		it -= x;
		return (*this);
	}
	rev_random_access_iterator	&operator-=(int x){
		it += x;
		return (*this);
	}
	rev_random_access_iterator	&operator=(const rev_random_access_iterator &rhs){
		
		return (*this);
	}
	T*	&operator*(void){
		return (it*);
	}
	template<typename A, typename B>
	friend bool	operator==(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it == rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator!=(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it != rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator<(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it < rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator>(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it > rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator<=(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it <= rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator>=(rev_random_access_iterator<A> lhs, rev_random_access_iterator<B> rhs){
		return (lhs.it >= rhs.it);
	}
};










#endif