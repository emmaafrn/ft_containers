#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <cstddef>
#include "Iterator.hpp"

namespace ft{

template<class T>
class reverse_iterator {
public:
	typedef T	iterator_type;
	typedef typename T::value_type	value_type;
	typedef typename T::difference_type	difference_type;
	typedef typename T::pointer	pointer;
	typedef typename T::reference	reference;
	typedef typename T::iterator_category iterator_category;
private:
	iterator_type it;
public:
	reverse_iterator(){
	}
	
	reverse_iterator(iterator_type it): it(it) {
	}
	reverse_iterator(const reverse_iterator &copy): it(copy.it) {
	}
	~reverse_iterator(){
	}
	reverse_iterator	&operator++(void){
		it--;
		return (*this);
	}
	reverse_iterator	operator++(int){
		reverse_iterator prev = *this;

		--it;
		return (prev);
	}
	reverse_iterator	&operator--(void){
		it++;
		return (*this);
	}
	reverse_iterator	operator--(int){
		reverse_iterator prev = this;

		++it;
		return (prev);
	}
	reverse_iterator	&operator-(const reverse_iterator &rhs){
		it = it + rhs.it;
		return (*this);
	}
	reverse_iterator	&operator+(int x){
		it = it - x;
		return (*this);
	}
	reverse_iterator	&operator-(int x){
		it = it + x;
		return (*this);
	}
	reverse_iterator	&operator+=(int x){
		it -= x;
		return (*this);
	}
	reverse_iterator	&operator-=(int x){
		it += x;
		return (*this);
	}
	void	operator=(const reverse_iterator &rhs){
		it = rhs.it;
	}
	value_type	&operator*(void){
		return (*it);
	}
	template<typename A, typename B>
	friend bool	operator==(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it == rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator!=(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it != rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator<(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it < rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator>(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it > rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator<=(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it <= rhs.it);
	}
	template<typename A, typename B>
	friend bool	operator>=(reverse_iterator<A> lhs, reverse_iterator<B> rhs){
		return (lhs.it >= rhs.it);
	}
};

}




#endif