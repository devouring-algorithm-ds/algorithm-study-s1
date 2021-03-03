#pragma once

class Node 
{
  private:
  public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}

    /*
    int getData() { return this->data; }

    void setNext(Node *node) { this->next = node; }
    Node* getNext() { return this->next; }
    */
};
