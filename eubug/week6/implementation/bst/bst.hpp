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
    bool search(int data);
    void remove(int data);
    Node* removeNode(Node *, int);
    Node* minValueNode(Node *);

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

bool BST::search(int data) {
  if( root->data == data ) return true;
  
  Node *temp = root;
  while(true) {
    if( temp==nullptr ) break;
    if( data < temp->data ) {
      temp = temp->left;
    } else if( data > temp->data ) {
      temp = temp->right;
    } else {
      return true;
    }
  }

  return false;
}

void BST::remove(int data) {
  removeNode(root, data);
}

Node* BST::removeNode(Node *node, int data) {
  if( node == nullptr) return node;

  if( data < node->data ) {
    node->left = removeNode(node->left, data);
  } else if( data > node->data ) {
    node->right = removeNode(node->right, data);
  } else {
    // node with only one child or no child 
    if( node->left == nullptr ) {
      Node *temp = node->right; 
      delete node;
      return temp;
    } else if ( node->right == nullptr ) {
      Node *temp = node->left;
      delete node;
      return temp;
    }

    // find the smallest node from the right child
    Node *temp = minValueNode(node->right);
    node->data = temp->data;
    node->right = removeNode(node->right, temp->data);
  }

  return node;
}

Node* BST::minValueNode(Node *node) {
  Node *curr = node;
  while( curr && curr->left != nullptr ) {
    curr = curr->left;
  }

  return curr;
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
