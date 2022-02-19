#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <ostream>

void	vector_erase(){
	std::cout << "BEFORE ERASE OF 4\n";
	std::vector<int> v;
	for (int i = 0; i < 8; i++) v.push_back(i);
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator after = v.begin();
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
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;

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
	
	std::vector<int> range;

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
	std::vector<int>			vect;
	

	for (int i = 42; i < 46 ; i++) vect.push_back(i);
	std::cout << "iterator\n";
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "reverse iterator\n";
	for (std::vector<int>::reverse_iterator rit = vect.rbegin() ; rit != vect.rend(); rit++) std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "iterator\n";
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	std::vector<int>			copy(vect);
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++) std::cout <<  *it << " ";
	std::cout << std::endl;
	
}

void	clear_test(){
std::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();

  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void  count_test(){
  std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
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
  std::map<char,int> mymap;
  std::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p = mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(std::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);
}

void	key_compare_test(){
  	std::map<char,int> mymap;

  std::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
  	std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}


void insert_many(std::map<int, int> & container, int n) {
  for (int i = 0; i < n; ++i) {
    container.insert(std::make_pair(i, i));
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
static std::map<int, int> m10;

void set_m10() {
  for (int i = 0; i < 10; ++i) {
    m10[i] = i;
  }
}

template <class T1, class T2, class Comp>
void insert(std::map<T1, T2, Comp> & container, T1 k, T2 v) {
  std::pair<T1, T2> val = std::make_pair(k, v);
  std::cout << "Inserting " << "(" << val.first << "," << val.second << ")" << std::endl;

  std::pair<typename std::map<T1, T2, Comp>::iterator, bool> ret = container.insert(val);

  std::cout << "Was present : " << ret.second << std::endl;
//   std::cout << "Iterator points to " << (*ret).first << std::endl;
}
void test_insert()
{
  std::map<int, int> m0;

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
  std::map<int, int> m;

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
  std::map<int, int> m1, m2;

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

  std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void test_erase() {
  std::map<int, int> m;

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
  std::map<int, int>::iterator it[2] = {m.begin(), m.end()};
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
struct KeyCompareInt {
  bool operator() (int x, int y) const { return -x / 2 < - y / 2; }
};
struct KeyCompareStr {
  bool operator() (std::string x, std::string y) const {
    return (x.empty() && !y.empty()) || (!x.empty() && !y.empty() && x[0] < y[0]);
  }
};

void test_lower_bound() {
  std::map<int, int> m = m10;
  m.erase(3);

  std::cout << "lower_bound of 2 in m : ";
  print_all_nl(m.lower_bound(2), m.end());
  std::cout << "lower_bound of 3 in m : ";
  print_all_nl(m.lower_bound(3), m.end());
  std::cout << "lower_bound of 4 in m : ";
  print_all_nl(m.lower_bound(4), m.end());
}

void test_upper_bound() {
  std::map<int, int> m = m10;
  m.erase(3);

  std::cout << "upper_bound of 2 in m : ";
  print_all_nl(m.upper_bound(2), m.end());
  std::cout << "upper_bound of 3 in m : ";
  print_all_nl(m.upper_bound(3), m.end());
  std::cout << "upper_bound of 4 in m : ";
  print_all_nl(m.upper_bound(4), m.end());
}

void test_equal_range() {
  std::map<int, int> m = m10;
  m.erase(3);
  std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> range;

  range = m.equal_range(2);
  std::cout << "equal_range of 2 in m : ";
  print_all_nl(range.first, range.second);
  std::cout << "equal_range of 3 in m : ";
  range = m.equal_range(3);
  print_all_nl(range.first, range.second);
}

void empty_test(){
  std::map<char,int> mymap;

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
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

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

void	map_tests(){
  std::cout << "______________ MAP _______________\n";
	set_m10();
  std::boolalpha(std::cout);

  std::cout << "--- Test lower_bound ---" << std::endl;
	test_lower_bound();
  std::cout << "--- Test upper_bound ---" << std::endl;
	test_upper_bound();
  std::cout << "--- Test equal_range ---" << std::endl;
	test_equal_range();
  std::cout << "--- Test insert ---" << std::endl;
  test_insert();
  std::cout << "--- Test erase ---" << std::endl;
  test_erase();
  std::cout << "--- Test swap ---" << std::endl;
  test_swap();
  std::cout << "--- Test clear ---" << std::endl;
  test_clear();
	// clear_test();
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
}

void	vector_tests(){
  std::cout << "______________ VECTOR _______________\n"; 
  vector_erase();
	vector_insert();
	vector_iterators();
}

void	stack_tests(){
  std::cout << "______________ STACK _______________\n"; 
	
}

int	main(void) {
	map_tests();
  vector_tests();
	stack_tests();
}