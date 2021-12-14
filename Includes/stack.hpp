#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack{
public:
	typedef				Container							container_type;
	typedef typename	container_type::value_type			value_type;
	typedef typename	container_type::reference			reference;
	typedef typename	container_type::const_reference	const_reference;
	typedef typename	container_type::size_type		size_type;
protected :
	container_type		container;
public :


explicit stack (const container_type& ctnr = container_type()){
	this->container = ctnr;
}

bool empty() const{
	return (container.empty());
}

size_type size() const{
	return (container.size());
}

value_type& top(){
	return (container[size() - 1]);
}
const value_type& top() const{
	return (container[size() - 1]);
}

void push (const value_type& val){
	container.push_back(val);
}

void pop(){
	container.pop_back();
}

template <class T2, class Container2>
friend bool operator== (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
template <class T2, class Container2>
friend bool operator!= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
template <class T2, class Container2>
friend bool operator<  (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
template <class T2, class Container2>
friend bool operator<= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
template <class T2, class Container2>
friend bool operator>  (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
template <class T2, class Container2>
friend bool operator>= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c == rhs.c);
}
template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c != rhs.c);
}
template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c < rhs.c);
}
template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c <= rhs.c);
}
template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c > rhs.c);
}
template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.c >= rhs.c);
}

}



#endif