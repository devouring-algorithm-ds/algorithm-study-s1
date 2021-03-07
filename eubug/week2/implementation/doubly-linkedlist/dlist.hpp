#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "node.hpp"

class Dlist 
{
  private:
    Node *head;
    Node *tail;
    int length;

  public:
    Dlist();
    Dlist(int val);
    ~Dlist();

    void insertFront(int val);
    void insertBack(int val);
    void insertAt(int val, int pos);
    int removeFront();
    int removeBack();
    int removeAt(int pos);

    bool isEmpty() { return length == 0; }
    int getLength() { return length; }
    void print();
};

/*********************************************
 * constructor
 ********************************************/
Dlist::Dlist() 
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

Dlist::Dlist(int val) 
{
  head = new Node(val);
  tail = head;
  length = 1;
}

/*********************************************
 * destructor 
 ********************************************/
Dlist::~Dlist() 
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
 * 2. link new node's next with the current head
 * 3. link head's prev with the newm node 
 * 4. update the head
 ********************************************/
void Dlist::insertFront(int val) 
{
  Node *newNode = new Node(val);

  if(length == 0) 
  {
    head = newNode;
    tail = newNode;
  }
  else if (length == 1) 
  {
    head = newNode;
    head->next = tail;
    tail->prev = head;
  }
  else
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }

  ++length;
}

/*********************************************
 * insert a new node at the end of the list 
 * *******************************************
 * 1. create a new node
 * 2. link tail's next with the new node
 * 3. link new node's previous with the tail
 * 4. update the tail
 ********************************************/
void Dlist::insertBack(int val) 
{
  Node *newNode = new Node(val);

  if(length == 0) 
  {
    head = newNode;
    tail = newNode;
  }
  else 
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  ++length;
}

/*********************************************
 * insert a new node at a desired index position
 * *******************************************
 * 1. create a new node
 * 2. create a temp var to store the head
 * 3. move to the node one previous the 'position'
 * 4. link new node's next
 * 5. link temp.next with the new node 
 ********************************************/
void Dlist::insertAt(int val, int pos)
{
  if (pos <= 0) insertFront(val);
  else if (pos >= length) insertBack(val);
  else 
  {
    Node *newNode = new Node(val);
    Node *temp = head;

    for(int i=0; i<pos-1; ++i)
    {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;

    ++length;
  }
}

/*********************************************
 * remove a node from the head
 * *******************************************
 * 1. create a temp var to store the head's next
 * 2. detach temp's prev node linking to the head
 * 3. delete head
 * 3. update the head
 ********************************************/
int Dlist::removeFront()
{
  if (length)
  { 
    int val = head->data;
    Node *temp = head->next;
    if(temp) temp->prev = nullptr;
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
 * 1. temporarily store tail's prev node to 'temp'
 * 2. disocnnect temp's next which is current tail
 * 3. remove the tail 
 * 4. update the tail
 ********************************************/
int Dlist::removeBack()
{
  if (length == 0) return -1;

  if (length == 1) 
  {
    return removeFront();
  }
  else 
  {
    int val = tail->data;
    Node *temp = tail->prev;
    temp->next = nullptr;
    delete tail;
    tail = temp;
    --length;

    return val;
  }
}

/*********************************************
 * remove a node located at the index position
 * *******************************************
 * 1. create a temp var to store the head
 * 2. move to the node at positioin - 1
 * 3. store temp.next at other temporary variable
 * 4. let temp.next be the next next node 
 * 5. remove a node at step 3
 ********************************************/
int Dlist::removeAt(int pos)
{
  if (pos <= 0) return removeFront();
  if (pos >= length) return removeBack();

  Node *temp = head;
  for(int i=0; i<pos-1; ++i)
  {
    temp = temp->next;
  }

  int val = temp->next->data;
  Node *deleteNode = temp->next;
  temp->next = deleteNode->next;
  deleteNode->next->prev = temp;
  delete deleteNode;

  --length;

  return val;
}

/*********************************************
 * display all nodes
 ********************************************/
void Dlist::print() 
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
