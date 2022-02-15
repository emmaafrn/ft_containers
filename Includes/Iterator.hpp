#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>
#include <iterator>

namespace ft{

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct Iterator
{
	public :
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

template<class T>
class ptr_iterator: public Iterator<std::random_access_iterator_tag, T>{
	public :
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef T*		pointer;
	typedef T&	reference;
	typedef std::random_access_iterator_tag	iterator_category;
	// typedef typename ptr_iterator::pointer pointer;
	// typedef std::ptr_iterator_tag	iterator_category;
private:
	pointer	_ptr;
public:
	ptr_iterator(void){
		_ptr = NULL;
	}
	ptr_iterator(const ptr_iterator &copy){
		_ptr = copy._ptr;
	}
	ptr_iterator(const pointer ptr){
		_ptr = ptr;
	}
	~ptr_iterator(){
		
	}
	ptr_iterator	&operator++(void){
		_ptr++;
		return (*this);
	}
	ptr_iterator	operator++(int){
		ptr_iterator	prev = *this;

		_ptr++;
		return (prev);
	}
	ptr_iterator	&operator--(void){
		_ptr--;
		return (*this);
	}
	ptr_iterator	operator--(int){
		ptr_iterator	prev = *this;

		_ptr--;
		return (prev);
	}
	friend int	operator-(const ptr_iterator &lhs, const ptr_iterator &rhs){
	int res = lhs._ptr - rhs._ptr;
		return (res);
	}
	friend ptr_iterator	operator+(const ptr_iterator &lhs, int x){
		ptr_iterator	it;

		it._ptr = lhs._ptr + x;
		return (it);
	}
	friend ptr_iterator	operator+(int x , const ptr_iterator &lhs){
		ptr_iterator	it;

		it._ptr = lhs._ptr + x;
		return (it);
	}
	friend ptr_iterator	operator-(const ptr_iterator &lhs, int x){
		ptr_iterator	it;

		it._ptr = lhs._ptr - x;
		return (it);
	}
	friend ptr_iterator	operator-(int x, const ptr_iterator &lhs){
		ptr_iterator	it;

		it._ptr = lhs._ptr - x;
		return (it);
	}
	ptr_iterator	operator+=(int x){
		_ptr += x;
		return (*this);
	}
	ptr_iterator	operator-=(int x){
		_ptr -= x;
		return (*this);
	}
	void	operator=(const ptr_iterator &rhs){
		_ptr = rhs._ptr;
	}
	value_type	&operator*(void){
		return (*_ptr);
	}
	reference	operator[](int n){
		return (_ptr[n]);
	}
	template<typename A, typename B>
	friend bool	operator==(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr == rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator!=(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr != rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator<(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr < rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator>(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr > rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator<=(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr <= rhs._ptr)
			return (1);
		return (0);
	}
	template<typename A, typename B>
	friend bool	operator>=(ptr_iterator<A> lhs, ptr_iterator<B> rhs){
		if (lhs._ptr >= rhs._ptr)
			return (1);
		return (0);
	}
};

}

#endif