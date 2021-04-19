/* https://github.com/joonas-yoon/Class-Algorithm/tree/master/Red-Black-Tree */

#pragma once

#define RED   0
#define BLACK 1
#define NIL 0

class RedBlackTree;

class Node {
  friend class RedBlackTree;
  private:
    int key;
    Node *left;
    Node *right;
    Node *parent;
    int color;

  public:
    Node() : key(), left(NIL), right(NIL), parent(NIL), color(RED) {;}
    Node(int key, Node *l = NIL, Node *r = NIL) : key(key), left(l), right(r), parent(NIL), color(RED) {;}
    Node(Node& node){
      key = node.key;
      parent = node.parent;
      left = node.left;
      right = node.right;
      color = node.color;
    }

    ~Node(){
      left = right = parent = NIL;
    }

    int getKey() const { return this->key; }
    Node *getUncle() {
      Node *p = this->parent;
      if (!p) return NIL;
      if (this->isLeftNode()) return p->right;
      else return p->left;
    }

    void setRedColor(){ this->color = RED; }
    void setBlackColor(){ this->color = BLACK; }
    void swapColor(Node *node){
      int c = this->color;
      this->color = node->color;
      node->color = c;
    }

    bool isRed() const { return this->color == RED; }
    bool isLeftNode() const {
      if (this->parent) return this->parent->left == this;
      return false;
    }
    bool isRightNode() const {
      if (this->parent) return this->parent->right == this;
      return false;
    }
    bool isLeaf() const {
      return !this->left || !this->right;
    }
};
