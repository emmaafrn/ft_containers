#include "Includes/Iterator.hpp"
#include "Includes/vector.hpp"
#include <iostream>
template <class Container>
void print_container(Container const & m) {
  for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin())
      std::cout << ", ";
    std::cout << *it;
  }
}
template <class Container>
void print_container_nl(Container const & m) {
  print_container(m);
  std::cout << std::endl;
}

namespace ft{
void test() {
  vector<int> vect1;
  vector<int> vect2;

  for (int i = 0; i < 10; i++) {
    vect1.push_back(i);
  }
  for (int i = 10; i < 20; i++) {
    vect2.push_back(i);
  }

  vector<int>::iterator it1 = vect1.begin() + 3;
  vector<int>::iterator it2 = vect2.begin() + 3;
  int* p1 = &vect1[4];
//   int* p2 = &vect2[4];
//   int& r1 = vect1[5];
//   int& r2 = vect2[5];

  print_container_nl(vect1);
  print_container_nl(vect2);
  vect1.swap(vect2);
  print_container_nl(vect1);
  print_container_nl(vect2);
//  std::cout << "p1 = " << std::endl;

//   std::cout << *it1 << std::endl;
//   std::cout << *it2 << std::endl;
  std::cout << *p1 << std::endl;
//   std::cout << *p2 << std::endl;
//   std::cout << r1 << std::endl;
//   std::cout << r2 << std::endl;
//   *it1 = -1;
//   *it2 = -2;
//   *p1 = -3;
//   *p2 = -4;
//   r1 = -5;
//   r2 = -6;
//   print_container_nl(vect1);
//   print_container_nl(vect2);
}
}

int	main(void){
	// std::allocator<int> alloc;
	// ft::vector<int> a(5, 42, alloc);
	// ft::vector<int> b(10, 24, alloc);
	// ft::vector<int>::iterator it;
	// ft::vector<int>::iterator ite;
	// int	*p1;
	// int	*p2;
	// int	&r1 = a[4];
	// int	&r2 = b[4];

	// a.pop_back();
	// a.push_back(4);
	
	// it = a.begin();
	// ite = a.end();
	// std::cout << "----------- A -----------\n";
	// while (it != ite){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	// std::cout << "----------- B -----------\n";
	// it = b.begin();
	// ite = b.end();
	// while (it != ite){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }

	// p1 = &a[3];
	// p2 = &b[3];

	// std::cout << "p1 = " << p1 << std::endl;
	// std::cout << "p2 = " << p2 << std::endl;
	// std::cout << "r1 = " << r1 << std::endl;
	// std::cout << "r2 = " << r2 << std::endl;
	// swap(a,b);
	// it = a.begin();
	// ite = a.end();
	// std::cout << "---------- AFTER SWAP -----------" << std::endl;
	// std::cout << "----------- A -----------\n";
	// while (it != ite){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	// std::cout << "----------- B -----------\n";
	// it = b.begin();
	// ite = b.end();
	// while (it != ite){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	// std::cout << "p1 = " << p1 << std::endl;
	// std::cout << "p2 = " << p2 << std::endl;
	// std::cout << "r1 = " << r1 << std::endl;
	// std::cout << "r2 = " << r2 << std::endl;
	// return (0);
	ft::test();
}