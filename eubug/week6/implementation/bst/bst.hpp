#include <iostream>
#include <queue>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::queue;

#include "node.hpp"

class BST {
  private: 
    Node *root = nullptr; // this worked??

  public: 
    BST():root(nullptr) {}
    ~BST();

    void insert(int data);
    void insertLeft(Node *node, int data);
    void insertRight(Node *node, int data);
    void deleteTree(Node *);

    void inorder();
    void inorderHelper(Node *temp);
};

BST::~BST() {
  deleteTree(root);
  root = nullptr;
}

void BST::deleteTree(Node *temp) {
  if (temp == nullptr) return;

  deleteTree(temp->left);
  deleteTree(temp->right);
  cout << "Deleting: " << temp->data << endl;
  delete temp;
}

void BST::insert(int data) {
  if( root==nullptr ) {
    root = new Node(data);
    return;
  }

  Node *temp = root;

  while(true) {
    if( data > temp->data ) {
      if ( temp->right == nullptr ) {
        temp->right = new Node(data);
        break;
      }
      temp = temp->right;
    } else {
      if( temp->left == nullptr ) {
        temp->left = new Node(data);
        break;
      }
      temp = temp->left;
    }
  }
}

void BST::inorder() {
  inorderHelper(root);
  cout << endl;
}

void BST::inorderHelper(Node *node) {
  if( node==nullptr ) return;

  inorderHelper(node->left);
  cout << node->data << ' ';
  inorderHelper(node->right);
}
