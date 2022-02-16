#include "Includes/map.hpp"

struct KeyCompareInt {
  bool operator() (int x, int y) const { return -x / 2 < - y / 2; }
};
struct KeyCompareStr {
  bool operator() (std::string x, std::string y) const {
    return (x.empty() && !y.empty()) || (!x.empty() && !y.empty() && x[0] < y[0]);
  }
};

void test_int() {
  ft::map<int, int, KeyCompareInt> m;

  for (int i = 0; i < 20; ++i)
    insert(m, i, i);

  for (int i = 0; i < 20; ++i)
    std::cout << m[i] << std::endl;
}

// void test_str() {
//   map<std::string, int, KeyCompareStr> m;

//   for (int i = 0; i < 20; ++i)
//     insert(m, std::to_string(i), i);

//   for (int i = 0; i < 20; ++i)
//     std::cout << m[std::to_string(i)] << std::endl;
// }

void test() {
  test_int();
  // test_str();
}
