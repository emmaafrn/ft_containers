#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

template<class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};

struct random_access_iterator_tag
{
	
};

template<class T>
class random_access_iterator : iterator<random_access_iterator_tag, T>{
private:

public:
	Iterator();
	~Iterator();
};





#endif