#include "Includes/Iterator.hpp"
#include "Includes/vector.hpp"
#include "Includes/stack.hpp"
#include "Includes/map.hpp"
#include "Includes/pair.hpp"
#include <iostream>


void	test_after_swap(){
	std::allocator<int> alloc;
	ft::vector<int> a(5, 42, alloc);
	ft::vector<int> b(10, 24, alloc);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator ite;
	int	*p1;
	int	*p2;
	int	&r1 = a[4];
	int	&r2 = b[4];

	a.pop_back();
	a.push_back(4);
	
	it = a.begin();
	ite = a.end();
	std::cout << "----------- A -----------\n";
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "----------- B -----------\n";
	it = b.begin();
	ite = b.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}

	p1 = &a[3];
	p2 = &b[3];

	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	std::cout << "r1 = " << r1 << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
	swap(a,b);
	it = a.begin();
	ite = a.end();
	std::cout << "---------- AFTER SWAP -----------" << std::endl;
	std::cout << "----------- A -----------\n";
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "----------- B -----------\n";
	it = b.begin();
	ite = b.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	std::cout << "r1 = " << r1 << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
}

void	insert_tests(){
	ft::vector<int> a;
	ft::vector<int> b;
	ft::vector<int> c;
	ft::ptr_iterator<int> it;
	ft::ptr_iterator<int> ite;

	std::cout << "---------- 1 ----------"<< std::endl;
	a.push_back(42);
	a.push_back(24);
	a.push_back(3);
	it = a.begin();
	ite = a.end();
	it = a.insert(++it, 500);
	ite = a.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "---------- 2 ----------"<< std::endl;
	int	x = 42;
	for (int i = 0; i < 10 ; i++) b.push_back(i);
	it = b.begin();
	ite = b.end();
	b.insert((it + 3), 5, x);
	ite = b.end();
	it = b.begin();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "---------- 3 ----------"<< std::endl;
	
	ft::vector<int> range;

	for (int i = 42; i < 46 ; i++) range.push_back(i);
	it = range.begin();
	ite = range.end();
	for (int i = 0; i < 10 ; i++) c.push_back(i);
	c.insert(c.begin() + 1, it, ite);
	it = c.begin();
	ite = c.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
}

void	iterators_tests() {
	ft::vector<int>			vect;
	

	for (int i = 42; i < 46 ; i++) vect.push_back(i);
	std::cout << "iterator\n";
	for (ft::ptr_iterator<int> it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "reverse iterator\n";
	// std::cout << "end = "<< *(vect.rend()) << std::endl;
	for (ft::vector<int>::reverse_iterator rit = vect.rbegin() ; rit != vect.rend(); rit++) std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "iterator\n";
	for (ft::ptr_iterator<int> it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	ft::vector<int>			copy(vect);
	for (ft::ptr_iterator<int> it = copy.begin(); it != copy.end(); it++) std::cout <<  *it << " ";
	std::cout << std::endl;
	
}

int	main(void) {
	// VECTOR
	// test_after_swap();
	// insert_tests();
	// iterators_tests();

	//STACK
	// ft::vector<int> v;

	// for (int i = 42; i < 46 ; i++) v.push_back(i);

	// ft::stack<int> s(v);

	// std::cout << "stack's top = " << s.top() << std::endl;

	//MAP
	ft::map<int, int> mamap;

	for(int i = 0; i < 10; i++){
		mamap.insert(ft::make_pair(i, i+1));
	}

	return (0);
}
