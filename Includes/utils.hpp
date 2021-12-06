#ifndef UTILS_HPP
# define UTILS_HPP

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