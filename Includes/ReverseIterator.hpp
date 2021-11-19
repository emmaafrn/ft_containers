#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <cstddef>

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

	}
	~rev_random_access_iterator(){

	}
	
};










#endif