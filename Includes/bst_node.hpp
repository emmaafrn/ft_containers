#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#define RED 0
#define BLACK 1

namespace ft {

template <class T> struct bst_node {
  typedef T value_type;
  typedef bst_node *node_pointer;

  bst_node(const value_type &val) : p(nullptr), l(nullptr), r(nullptr), value(val), color(RED) {}

  bst_node(node_pointer parent, node_pointer left, node_pointer right,
           const value_type &val, bool colo)
      : p(parent), l(left), r(right), value(val), color(colo) {}

  node_pointer  p;     // parent
  node_pointer  l;     // left_child
  node_pointer  r;     // right_child
  value_type    value; // content
  bool          color;
};

}

#endif