#include "Includes/Iterator.hpp"
#include "Includes/Vector.hpp"
#include <iostream>


int	main(void){
	std::allocator<int> alloc;
	vector<int> a(5, 42, alloc);
	vector<int>::iterator it;

	a.pop_back();
	a.push_back(24);
	

	return (0);
}