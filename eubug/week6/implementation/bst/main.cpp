#include <iostream>

using namespace std;

#include "bst.hpp"

int main() {
  BST bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);
  bst.inorder();

  bst.remove(20);
  bst.inorder();
  bst.remove(30);
  bst.inorder();
  bst.remove(50);
  bst.inorder();

  return 0;
}
