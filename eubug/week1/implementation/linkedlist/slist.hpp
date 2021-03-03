#include <iostream>

using namespace std;

#include "node.hpp"

class Slist 
{
  private:
    Node *head;
    int length;

  public:
    Slist();
    ~Slist();

    void insertFront(int val);
    void insertBack(int val);
    int removeFirst();
    int removeLast();

    bool isEmpty() { return length == 0; }
    int getLength() { return length; }
    void print();
};

/*********************************************
 * constructor
 ********************************************/
Slist::Slist() 
{
  head = nullptr;
  length = 0;
}

/*********************************************
 * destructor 
 ********************************************/
Slist::~Slist() 
{
  cout << "-- calling the destructor" << endl;
  while(head) 
  {
    Node *temp = head->next;
    cout << "-- deleting: " << head->data << endl;
    delete head;
    head = temp;
  }
  cout << "-- returning from the destructor" << endl;
}

/*********************************************
 * insert a new node at the head of the list 
 * *******************************************
 * 1. create a new node
 * 2. let current node points to the current head
 * 3. update the head
 ********************************************/
void Slist::insertFront(int val) 
{
  Node *newNode = new Node(val);

  if(head == nullptr) 
  {
    head = newNode;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }

  ++length;
}

/*********************************************
 * insert a new node at the end of the list 
 * *******************************************
 * 1. create a new node
 * 2. create a temp var to store the head
 * 3. move to the tail of the list
 * 4. insert the new node at the end 
 ********************************************/
void Slist::insertBack(int val) 
{
  Node *newNode = new Node(val);
  Node *temp = head;

  while(temp->next != nullptr) 
    temp = temp->next; 

  temp->next = newNode;

  ++length;
}

/*********************************************
 * remove a node from the head
 * *******************************************
 * 1. create a temp var to store the head.next
 * 2. remove the head
 * 3. let temp var be the new head
 ********************************************/
int Slist::removeFirst()
{
  if (length)
  { 
    Node *temp = head->next;
    int val = head->data;
    delete head;
    head = temp;
    --length;

    return val;
  }

  return -1;
}

/*********************************************
 * remove a node from the tail
 * *******************************************
 * 1. create a temp var to store the head
 * 2. move to the one before the tail node
 * 3. remove the tail node using temp.next
 ********************************************/
int Slist::removeLast()
{
  if (length == 0) return -1;

  if (length == 1) 
  {
    return removeFirst();
  }
  else 
  {
    Node *temp = head;
    for(int i=0; i<length-2; ++i)
    {
      temp = temp->next;
    }

    int val = temp->next->data;
    delete temp->next;
    temp->next = nullptr;

    --length;

    return val;
  }
}

/*********************************************
 * display all nodes
 ********************************************/
void Slist::print() 
{
  if (length == 0) 
  {
    cout << "List is empty..." << endl;
    return;
  }
  Node *temp = head;

  while(temp) 
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}
