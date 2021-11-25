#include "Includes/Iterator.hpp"
#include "Includes/vector.hpp"
#include <iostream>


int	main(void){
	std::allocator<int> alloc;
	ft::vector<int> a(5, 42, alloc);
	ft::vector<int> b(10, 24, alloc);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator ite;
	int	*p1;
	int	*p2;

	a.pop_back();
	a.push_back(4);
	
	it = a.begin() + 2;
	ite = a.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	p1 = &a[4];
	p2 = &b[4];

	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	swap(a,b);
	it = a.begin();
	ite = a.end();
	std::cout << "-----------------------" << std::endl;
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	return (0);
}