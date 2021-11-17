#include "Includes/Iterator.hpp"
#include "Includes/Vector.hpp"
#include <iostream>

int	main(void){
	std::allocator<int> alloc;
	vector<int> a(5, 42, alloc);

	a.pop_back();
	a.push_back(24);
	
	// for (int i = 0; a[i] ; i++){
	// 	std::cout << a[i] << std::endl;
	// }

	return (0);
}