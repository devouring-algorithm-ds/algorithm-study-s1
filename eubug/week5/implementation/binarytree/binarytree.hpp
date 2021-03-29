#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::queue;

#include "node.hpp"

class BinaryTree {
  private: 
    Node *root = nullptr; // this worked??

  public: 
    BinaryTree():root(nullptr) {}
    ~BinaryTree();

    void insertNode(char);
    void inorder(bool);
    void preorder(bool);
    void postorder(bool);

    void inorderHelper(Node *, bool);
    void preorderHelper(Node *, bool);
    void postorderHelper(Node *, bool);

    void deleteTree(Node *);
};

void BinaryTree::deleteTree(Node *temp) {
  if (temp == nullptr) return;

  deleteTree(temp->left);
  deleteTree(temp->right);
  cout << "Deleting: " << temp->data << endl;
  delete temp;
}

BinaryTree::~BinaryTree() {
  deleteTree(root);
  root = nullptr;
}

void BinaryTree::insertNode(char data) {
  if ( root == nullptr ) {
    root = new Node(data);
    return ;
  }  else {
    queue<Node *> q;
    q.push(root);

    while( !q.empty() ) {
      Node *temp = q.front();
      q.pop();

      if( temp->data == data ) {
        ++(temp->count);
        return;
      }

      if( temp->left != nullptr )  {
        q.push( temp->left );
      } else {
        temp->left = new Node(data);
        return;
      }

      if( temp->right != nullptr ) {
        q.push( temp->right );
      } else {
        temp->right = new Node(data);
        return ;
      }
    }
  }
}

void BinaryTree::inorder(bool printCount) {
  inorderHelper(root, printCount);
}

void BinaryTree::preorder(bool printCount) {
  preorderHelper(root, printCount);
}

void BinaryTree::postorder(bool printCount) {
  postorderHelper(root, printCount);
}

void BinaryTree::inorderHelper(Node *root, bool printCount) {
  if (root == nullptr) return;

  inorderHelper(root->left, printCount);
  if (printCount) cout << "(" << root->data << ", " << root->count << ") ";
  else cout << root->data << " ";
  inorderHelper(root->right, printCount);
}

void BinaryTree::preorderHelper(Node *root, bool printCount) {
  if (root == nullptr) return;

  if (printCount) cout << "(" << root->data << ", " << root->count << ") ";
  else cout << root->data << " ";
  preorderHelper(root->left, printCount);
  preorderHelper(root->right, printCount);
}

void BinaryTree::postorderHelper(Node *root, bool printCount) {
  if (root == nullptr) return;

  postorderHelper(root->left, printCount);
  postorderHelper(root->right, printCount);
  if (printCount) cout << "(" << root->data << ", " << root->count << ") ";
  else cout << root->data << " ";
}
