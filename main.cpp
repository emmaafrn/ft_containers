#include "Includes/Iterator.hpp"
#include "Includes/vector.hpp"
#include "Includes/map.hpp"
#include "Includes/stack.hpp"
#include "Includes/map.hpp"
#include "Includes/pair.hpp"
#include "Includes/map_iterator.hpp"
#include <iostream>
#include <ostream>
#include <map>
#include <stack>
#include <vector>

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#endif

void	vector_erase(){
	std::cout << "BEFORE ERASE OF 4\n";
	TEST_NAMESPACE::vector<int> v;
	for (int i = 0; i < 8; i++) v.push_back(i);
	TEST_NAMESPACE::vector<int>::iterator it = v.begin();
	TEST_NAMESPACE::vector<int>::iterator after = v.begin();
	while (it != v.end()){
		std::cout << *it << std::endl;
		it++;
	}
	int i = 0;
	it = v.begin();
	while (i <= 3){
		it++;
		i++;
	}
	v.erase(it);
	std::cout << "AFTER ERASE OF 4\n";
	after = v.begin();
	while (after != v.end()){
		std::cout << *after << std::endl;
		after++;
	}
}

void	vector_insert(){
	TEST_NAMESPACE::vector<int> a;
	TEST_NAMESPACE::vector<int> b;
	TEST_NAMESPACE::vector<int> c;
	TEST_NAMESPACE::vector<int>::iterator it;
	TEST_NAMESPACE::vector<int>::iterator ite;

	std::cout << "---------- 1 ----------"<< std::endl;
	a.push_back(42);
	a.push_back(24);
	a.push_back(3);
	it = a.begin();
	ite = a.end();
	it = a.insert(++it, 500);
	it = a.begin();
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
	
	TEST_NAMESPACE::vector<int> range;

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

void	vector_iterators() {
	TEST_NAMESPACE::vector<int>			vect;
	

	for (int i = 42; i < 46 ; i++) vect.push_back(i);
	std::cout << "iterator\n";
	for (TEST_NAMESPACE::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "reverse iterator\n";
	for (TEST_NAMESPACE::vector<int>::reverse_iterator rit = vect.rbegin() ; rit != vect.rend(); rit++) std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "iterator\n";
	for (TEST_NAMESPACE::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	TEST_NAMESPACE::vector<int>			copy(vect);
	for (TEST_NAMESPACE::vector<int>::iterator it = copy.begin(); it != copy.end(); it++) std::cout <<  *it << " ";
	std::cout << std::endl;
	
}

void	clear_test(){
TEST_NAMESPACE::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (TEST_NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();

  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (TEST_NAMESPACE::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void	count_test(){
	TEST_NAMESPACE::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
}

void	get_allocator_test(){
  int psize;
  TEST_NAMESPACE::map<char,int> mymap;
  TEST_NAMESPACE::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p = mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(TEST_NAMESPACE::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);
}

void	key_compare_test(){
  	TEST_NAMESPACE::map<char,int> mymap;

  TEST_NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  TEST_NAMESPACE::map<char,int>::iterator it = mymap.begin();
  do {
  	std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}

void insert_many(TEST_NAMESPACE::map<int, int> & container, int n) {
  for (int i = 0; i < n; ++i) {
    container.insert(TEST_NAMESPACE::make_pair(i, i));
  }
}

template <class Container>
void print_container(Container const & m) {
  for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin())
      std::cout << ", ";
    std::cout << "(" << (*it).first << "," << (*it).second << ")";
  }
}
template <class Container>
void print_container_nl(Container const & m) {
  print_container(m);
  std::cout << std::endl;
}
template <class Iterator>
void print_all(Iterator first, Iterator last) {
  for (Iterator it = first; it != last; ++it) {
    if (it != first)
      std::cout << ", ";
    std::cout << "(" << (*it).first << "," << (*it).second << ")";
  }
}
template <class Iterator>
void print_all_nl(Iterator first, Iterator last) {
  print_all(first, last);
  std::cout << std::endl;
}
static TEST_NAMESPACE::map<int, int> m10;

void set_m10() {
  for (int i = 0; i < 10; ++i) {
    m10[i] = i;
  }
}

template <class T1, class T2, class Comp>
void insert(TEST_NAMESPACE::map<T1, T2, Comp> & container, T1 k, T2 v) {
  TEST_NAMESPACE::pair<T1, T2> val = TEST_NAMESPACE::make_pair(k, v);
  std::cout << "Inserting " << "(" << val.first << "," << val.second << ")" << std::endl;

  TEST_NAMESPACE::pair<typename TEST_NAMESPACE::map<T1, T2, Comp>::iterator, bool> ret = container.insert(val);

  std::cout << "Was present : " << ret.second << std::endl;
//   std::cout << "Iterator points to " << (*ret).first << std::endl;
}
void test_insert()
{
  TEST_NAMESPACE::map<int, int> m0;

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
  TEST_NAMESPACE::map<int, int> m;

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
  TEST_NAMESPACE::map<int, int> m1, m2;

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
  TEST_NAMESPACE::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (TEST_NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (TEST_NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';
}

void test_erase() {
  TEST_NAMESPACE::map<int, int> m;

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
  TEST_NAMESPACE::map<int, int>::iterator it[2] = {m.begin(), m.end()};
  it[0]++; it[0]++;
  it[1]--; it[1]--;
  m.erase(it[0], it[1]);
  print_container_nl(m);
  std::cout << "size = " << m.size() << std::endl;
  // TEST IF ITERATOR STILL CORRECT AFTER ERASE
  TEST_NAMESPACE::map<int, int> z;
  for(int i = 0; i< 10; i++){
    z.insert(TEST_NAMESPACE::make_pair(i, i));
  }
  std::cout << z.size();
  TEST_NAMESPACE::map<int, int>::iterator y = z.begin();
  int x = 0;
  while (x < 4){
    y++;
    x++;
  }
  z.erase(3);
  std::cout << z.size();
  std::cout << y->first << std::endl;
}

struct KeyCompareInt {
  bool operator() (int x, int y) const { return -x / 2 < - y / 2; }
};
struct KeyCompareStr {
  bool operator() (std::string x, std::string y) const {
    return (x.empty() && !y.empty()) || (!x.empty() && !y.empty() && x[0] < y[0]);
  }
};

void test_lower_bound() {
  TEST_NAMESPACE::map<int, int> m = m10;
  m.erase(3);

  std::cout << "lower_bound of 2 in m : ";
  print_all_nl(m.lower_bound(2), m.end());
  std::cout << "lower_bound of 3 in m : ";
  print_all_nl(m.lower_bound(3), m.end());
  std::cout << "lower_bound of 4 in m : ";
  print_all_nl(m.lower_bound(4), m.end());
}

void test_upper_bound() {
  TEST_NAMESPACE::map<int, int> m = m10;
  m.erase(3);

  std::cout << "upper_bound of 2 in m : ";
  print_all_nl(m.upper_bound(2), m.end());
  std::cout << "upper_bound of 3 in m : ";
  print_all_nl(m.upper_bound(3), m.end());
  std::cout << "upper_bound of 4 in m : ";
  print_all_nl(m.upper_bound(4), m.end());
}

void test_equal_range() {
  TEST_NAMESPACE::map<int, int> m = m10;
  m.erase(3);
  TEST_NAMESPACE::pair<TEST_NAMESPACE::map<int, int>::iterator, TEST_NAMESPACE::map<int, int>::iterator> range;

  range = m.equal_range(2);
  std::cout << "equal_range of 2 in m : ";
  print_all_nl(range.first, range.second);
  std::cout << "equal_range of 3 in m : ";
  range = m.equal_range(3);
  print_all_nl(range.first, range.second);
}

void empty_test(){
  TEST_NAMESPACE::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
}
void  find_test(){
  TEST_NAMESPACE::map<char,int> mymap;
  TEST_NAMESPACE::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	max_size_test(){
	int i;
  TEST_NAMESPACE::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
}

void	map_copy_construct_assign(){
  TEST_NAMESPACE::map<int, int> m;

  for (int i = 0; i < 1000; i++) {
    m[i] = i;
  }
  
  
  TEST_NAMESPACE::map<int, int> m_copy(m);
  for(TEST_NAMESPACE::map<int, int>::iterator it = m_copy.begin(); it != m_copy.end(); it++) std::cout << it->first << std::endl;

  TEST_NAMESPACE::map<int, int> m_assign;
  m_assign = m;
  for(TEST_NAMESPACE::map<int, int>::iterator it = m_assign.begin(); it != m_assign.end(); it++) std::cout << it->first << std::endl;

  // Make sure all was duplicated
  m.clear();
  for(TEST_NAMESPACE::map<int, int>::iterator it = m_copy.begin(); it != m_copy.end(); it++) std::cout << it->first << std::endl;
  for(TEST_NAMESPACE::map<int, int>::iterator it = m_assign.begin(); it != m_assign.end(); it++) std::cout << it->first << std::endl;
}

void	map_iterators(){
	TEST_NAMESPACE::map<int, int> bst;

 	for (int i = 0; i < 15; ++i){
 	 	bst.insert(TEST_NAMESPACE::make_pair(i, i));
		std::cout << "i = " << i << std::endl;
	 	for (TEST_NAMESPACE::map<int, int>::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it)
	 	std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
	}

 	std::cout << "iterator" << std::endl;
 	for (TEST_NAMESPACE::map<int, int>::iterator it = bst.begin(); it != bst.end(); ++it)
 	  std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
 	std::cout << "END" << std::endl;

 	std::cout << "reverse iterator" << std::endl;
 	for (TEST_NAMESPACE::map<int, int>::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it)
 	  std::cout << "("  << it->first << ", " << it->second << "), " << std::endl;
 	std::cout << "END" << std::endl;
}

void  vector_reserve(){
  TEST_NAMESPACE::vector<int>::size_type sz;

  TEST_NAMESPACE::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  TEST_NAMESPACE::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
}

void  vector_empty(){
  TEST_NAMESPACE::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}

void	vector_at(){
	TEST_NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}

void	vector_front(){
  TEST_NAMESPACE::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void  vector_back(){
  TEST_NAMESPACE::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void	vector_assign(){
  TEST_NAMESPACE::vector<int> first;
  TEST_NAMESPACE::vector<int> second;
  TEST_NAMESPACE::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  TEST_NAMESPACE::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}

void	vector_capacity_and_size(){
  TEST_NAMESPACE::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void	vector_get_alloc(){
  TEST_NAMESPACE::vector<int> myvector;
  int * p;
  unsigned int i;
  
  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);
  
  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
  
  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';
  
  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);
}

void	stack_empty(){
  TEST_NAMESPACE::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';
}

void	stack_size(){
  TEST_NAMESPACE::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}

void	stack_top(){
  TEST_NAMESPACE::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void	stack_push(){
  TEST_NAMESPACE::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void	stack_pop(){
  TEST_NAMESPACE::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void	map_tests(){
	std::cout << "______________ MAP _______________\n"; 
	set_m10();

	std::cout << "--- Test insert ---" << std::endl;
	test_insert();
	std::cout << "--- Test erase ---" << std::endl;
	test_erase();
	std::cout << "--- Test swap ---" << std::endl;
	test_swap();
	std::cout << "--- Test clear ---" << std::endl;
	test_clear();
	clear_test();
	std::cout << "--- Test assign and copy constructor ---" << std::endl;
	map_copy_construct_assign();
	std::cout << "--- Test iterators ---" << std::endl;
	map_iterators();
	std::cout << "--- Test lower_bound ---" << std::endl;
	test_lower_bound();
	std::cout << "--- Test upper_bound ---" << std::endl;
	test_upper_bound();
	std::cout << "--- Test equal_range ---" << std::endl;
	test_equal_range();
	std::cout << "--- Test count ---" << std::endl;
	count_test();
	std::cout << "--- Test get_allocator ---" << std::endl;
	get_allocator_test();
	std::cout << "--- Test key_compare ---" << std::endl;
	key_compare_test();
	std::cout << "--- Test insert ---" << std::endl;
	test_insert();
	std::cout << "--- Test erase ---" << std::endl;
	test_erase();
	std::cout << "--- Test empty ---" << std::endl;
	empty_test();
	std::cout << "--- Test find ---" << std::endl;
	find_test();
	std::cout << "--- Test max_size ---" << std::endl;
	max_size_test();
}

void	vector_tests(){
	std::cout << "______________ VECTOR _______________\n";

	std::cout << "--- Test erase ---" << std::endl;
	vector_erase();
	std::cout << "--- Test insert ---" << std::endl;
	vector_insert();
	std::cout << "--- Test iterators ---" << std::endl;
	vector_iterators();
	std::cout << "--- Test reserve ---" << std::endl;
	vector_reserve();
	std::cout << "--- Test empty ---" << std::endl;
	vector_empty();
	std::cout << "--- Test at ---" << std::endl;
	vector_at();
	std::cout << "--- Test front ---" << std::endl;
	vector_front();
	std::cout << "--- Test back ---" << std::endl;
	vector_back();
	std::cout << "--- Test assign ---" << std::endl;
	vector_assign();
	std::cout << "--- Test size/capacity/max_size ---" << std::endl;
	vector_capacity_and_size();
	std::cout << "--- Test get_allocator ---" << std::endl;
	vector_get_alloc();
}

void	stack_tests(){
	std::cout << "______________ STACK _______________\n";
	
	std::cout << "--- Test empty ---" << std::endl;
	stack_empty();
	std::cout << "--- Test size ---" << std::endl;
	stack_size();
	std::cout << "--- Test top ---" << std::endl;
	stack_top();
	std::cout << "--- Test push ---" << std::endl;
	stack_push();
	std::cout << "--- Test pop ---" << std::endl;
	stack_pop();
}

int	main(void) {

	map_tests();
	vector_tests();
	stack_tests();
	return 0;
}