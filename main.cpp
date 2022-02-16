#include "Includes/Iterator.hpp"
#include "Includes/vector.hpp"
#include "Includes/map.hpp"
#include "Includes/stack.hpp"
#include "Includes/map.hpp"
#include "Includes/pair.hpp"
#include "Includes/map_iterator.hpp"
#include <iostream>
#include <ostream>


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

void	clear_test(){
ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();

  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void	get_allocator_test(){
  int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p = mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);
}

void	key_compare_test(){
  	ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
  	std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}

void	lower_bound_test(){
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;  

  mymap['a'] = 20;
  mymap['b'] = 40;
  mymap['c'] = 60;
  mymap['d'] = 80;
  mymap['e'] = 100;
  
  itlow = mymap.lower_bound ('b');  // itlow points to b
  itup = mymap.upper_bound ('d');   // itup points to e (not d!)  
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
}

void insert_many(ft::map<int, int> & container, int n) {
  for (int i = 0; i < n; ++i) {
    container.insert(ft::make_pair(i, i));
  }
}

template <class Container>
void print_container(Container const & m) {
  for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin())
      std::cout << ", ";
    std::cout << "(" << (*it).first << "," << (*it).second << ")";;
  }
}
template <class Container>
void print_container_nl(Container const & m) {
  print_container(m);
  std::cout << std::endl;
}
template <class T1, class T2, class Comp>
void insert(ft::map<T1, T2, Comp> & container, T1 k, T2 v) {
  ft::pair<T1, T2> val = ft::make_pair(k, v);
  std::cout << "Inserting " << "(" << val.first << "," << val.second << ")" << std::endl;

  ft::pair<typename ft::map<T1, T2, Comp>::iterator, bool> ret = container.insert(val);

  std::cout << "Was present : " << ret.second << std::endl;
//   std::cout << "Iterator points to " << (*ret).first << std::endl;
}
void test_insert()
{
  ft::map<int, int> m0;

  std::boolalpha(std::cout);
  for (int i = 0; i < 5; ++i) {
    insert(m0, i, i);
  }
  for (int i = 0; i < 5; ++i) {
    insert(m0, i, 2 * i);
  }

  insert_many(m0, 10000);
}

void test_clear() {
  srand(time(NULL));
  ft::map<int, int> m;

  for (int i = 0; i < 1000 ; ++i) {
    m[i] = rand();
    if (i > 0)
      std::cout << ", ";
  }
  m.clear();
  print_container_nl(m);
  std::cout << m.size();
}

void test_swap() {
  ft::map<int, int> m1, m2;

  for (int i = 0; i < 10; ++i) {
    m1[i] = i;
    m2[i] = 10 + i;
  }
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
  std::cout << "m1.swap(m2)..." << std::endl;
  m1.swap(m2);
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
  std::cout << "swap(m1, m2)..." << std::endl;
  swap(m1, m2);
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
}

void test_erase() {
  ft::map<int, int> m;

  for (int i = 0; i < 10; ++i) {
    m[i] = i;
  }
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  m.erase(m.begin());
  m.erase(--(m.end()));
  print_container_nl(m);
  ft::map<int, int>::iterator it[2] = {m.begin(), m.end()};
  it[0]++; it[0]++;
  it[1]--; it[1]--;
  m.erase(it[0], it[1]);
  print_container_nl(m);
  std::cout << "size = " << m.size() << std::endl;
}


void test() {
  std::cout << "--- Test insert ---" << std::endl;
  test_insert();
  std::cout << "--- Test erase ---" << std::endl;
  test_erase();
  std::cout << "--- Test swap ---" << std::endl;
  test_swap();
  std::cout << "--- Test clear ---" << std::endl;
  test_clear();
}

int	main(void) {
	// VECTOR
	// test_after_swap();
	// insert_tests();
	// iterators_tests();
	// ERASE
	// std::cout << "BEFORE ERASE OF 4\n";
	// ft::vector<int> v;
	// for (int i = 0; i < 8; i++) v.push_back(i);
	// ft::vector<int>::iterator it = v.begin();
	// ft::vector<int>::iterator after = v.begin();
	// while (it != v.end()){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	// int i = 0;
	// it = v.begin();
	// while (i <= 3){
	// 	it++;
	// 	i++;
	// }
	// v.erase(it);
	// std::cout << "AFTER ERASE OF 4\n";
	// after = v.begin();
	// while (after != v.end()){
	// 	std::cout << *after << std::endl;
	// 	after++;
	// }


	//STACK
	// ft::vector<int> v;

	// for (int i = 42; i < 46 ; i++) v.push_back(i);

	// ft::stack<int> s(v);

	// std::cout << "stack's top = " << s.top() << std::endl;

	//MAP
	test();
	// ft::map<int, int> m;

	// for (int i = 0; i < 100; i++) {
	//   m[i] = i;
	//   std::cout << "m[i] = " << m[i] << std::endl;
	// }
	// for (int i = 0; i < 100; i++) {
	//   std::cout << m[i] << " ";
	// }
	// std::cout << std::endl;

	// return (0);
//   ft::map<int, int> m;

//   for (int i = 0; i < 1000; i++) {
//     m[i] = i;
//   }
  
  
//   ft::map<int, int> m_copy(m);
//   for(ft::map<int, int>::iterator it = m_copy.begin(); it != m_copy.end(); it++) std::cout << it->first << std::endl;

//   ft::map<int, int> m_assign;
//   m_assign = m;
//   for(ft::map<int, int>::iterator it = m_assign.begin(); it != m_assign.end(); it++) std::cout << it->first << std::endl;

//   // Make sure all was duplicated
//   m.clear();
//   for(ft::map<int, int>::iterator it = m_copy.begin(); it != m_copy.end(); it++) std::cout << it->first << std::endl;
//   for(ft::map<int, int>::iterator it = m_assign.begin(); it != m_assign.end(); it++) std::cout << it->first << std::endl;
	
	// ft::map<int, int> bst;

 	// for (int i = 0; i < 15; ++i){
 	//  	bst.insert(ft::make_pair(i, i));
	// 	// std::cout << "i = " << i << std::endl;
	//  	// for (ft::map<int, int>::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it)
	//  	// std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
	// }

 	// // std::cout << "Mutable iterator" << std::endl;
 	// for (ft::map<int, int>::iterator it = bst.begin(); it != bst.end(); ++it)
 	//   std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
 	// std::cout << "END" << std::endl;

	// bst.ft_print(0);
 	// std::cout << "Mutable reverse iterator" << std::endl;
 	// for (ft::map<int, int>::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it)
 	//   std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
 	// std::cout << "END" << std::endl;
}	
