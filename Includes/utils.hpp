#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>
#include <iterator>
template <class Iterator>
class iterator_traits{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};
template <class T>
class iterator_traits<T*>{
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};
template <class T>
class iterator_traits<const T*>{
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template <bool Cond, class T = void> 
struct enable_if
{

};

template<class T>
struct enable_if<true,T>
{	
	typedef T 		type; 
};

template <class T>
struct is_integral{
	static const bool value = 0;
};

template <>
struct is_integral<bool>{
	static const bool value = 1;
};

template <>
struct is_integral<char>{
	static const bool value = 1;
};

template <>
struct is_integral<wchar_t>{
	static const bool value = 1;
};

template <>
struct is_integral<signed char>{
	static const bool value = 1;
};

template <>
struct is_integral<short int>{
	static const bool value = 1;
};

template <>
struct is_integral<int>{
	static const bool value = 1;
};

template <>
struct is_integral<long int>{
	static const bool value = 1;
};

template <>
struct is_integral<long long int>{
	static const bool value = 1;
};


#endif