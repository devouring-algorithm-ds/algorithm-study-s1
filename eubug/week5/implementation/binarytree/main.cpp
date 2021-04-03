#include "binarytree.hpp"

int main() {
  BinaryTree bt;

  bt.insertNode('A');
  bt.insertNode('B');
  bt.insertNode('C');
  bt.insertNode('D');
  bt.insertNode('E');
  bt.insertNode('F');
  bt.insertNode('G');
  bt.insertNode('H');
  bt.insertNode('I');

  cout << "Inorder: ";
  bt.inorder(0);
  cout << endl;

  cout << "Preorder: ";
  bt.preorder(0);
  cout << endl;

  cout << "Postorder: ";
  bt.postorder(0);
  cout << endl;

  cout << "Delete last leaf node" << endl;
  cout << "Deleting the last leaf node: " << bt.deleteNode() << endl;
  cout << "Deleting the last leaf node: " << bt.deleteNode() << endl;
  cout << "Deleting the last leaf node: " << bt.deleteNode() << endl;
  cout << "Deleting the last leaf node: " << bt.deleteNode() << endl;
  cout << "Deleting the last leaf node: " << bt.deleteNode() << endl;
  return 0;
}
