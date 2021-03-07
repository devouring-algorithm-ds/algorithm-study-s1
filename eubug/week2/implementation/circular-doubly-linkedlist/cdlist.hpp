#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "node.hpp"

class CDlist 
{
  private:
    Node *head;
    Node *tail;
    int length;

  public:
    CDlist();
    CDlist(int val);
    ~CDlist();

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
CDlist::CDlist() 
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

CDlist::CDlist(int val) 
{
  head = new Node(val);
  tail = head;
  head->prev = head->next = tail;
  tail->prev = tail->next = head;
  length = 1;
}

/*********************************************
 * destructor 
 ********************************************/
CDlist::~CDlist() 
{
  cout << "-- calling the destructor" << endl;
  for(int i=0; i<length; ++i)
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
void CDlist::insertFront(int val) 
{
  Node *newNode = new Node(val);

  if(length == 0) 
  {
    head = newNode;
    tail = newNode;
    head->prev = head->next = tail;
    tail->prev = tail->next = head;
  }
  else if (length == 1) 
  {
    head = newNode;
    head->next = head->prev = tail;
    tail->next = tail->prev = head;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  ++length;
}

/*********************************************
 * insert a new node at the end of the list 
 * *******************************************
 * 1. create a new node:
 * 2. link tail's next with the new node
 * 3. link new node's previous with the tail
 * 4. update the tail
 ********************************************/
void CDlist::insertBack(int val) 
{
  Node *newNode = new Node(val);

  if(length == 0) 
  {
    head = newNode;
    tail = newNode;
    head->prev = head->next = tail;
    tail->prev = tail->next = head;
  }
  else 
  {
    tail->next = newNode;
    newNode->next = head;
    head->prev = newNode;
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
void CDlist::insertAt(int val, int pos)
{
  if (pos <= 0) insertFront(val);
  else if (pos >= length-1) insertBack(val);
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
int CDlist::removeFront()
{
  if (length)
  { 
    int val = head->data;
    tail->next = head->next;
    head->next->prev = tail;
    delete head;
    head = tail->next;
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
int CDlist::removeBack()
{
  if (length == 0) return -1;

  if (length == 1) 
  {
    return removeFront();
  }
  else 
  {
    int val = tail->data;
    cout << "val: " << val << endl;
    tail->prev->next = head;
    head->prev = tail->prev;
    cout << "here2" << endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    delete tail;
    tail = head->prev;
    --length;

    return val;
  }
}

/*********************************************
 * remove a node located at the index position
 * *******************************************
 * 1. create a temp var to store the head
 * 2. move to the node to be deleted
 * 3. re-link temp's prev and next
 * 4. delete the current temp
 ********************************************/
int CDlist::removeAt(int pos)
{
    cout << "removeAt head: " << head->data << endl;
    cout << "removeAt tail: " << tail->data << endl;
  if (pos <= 0) return removeFront();
  if (pos >= length-1) {
    cout << "here" << endl;
    return removeBack();
  }

  Node *temp = head;
  for(int i=0; i<pos; ++i) 
    temp = temp->next;

  int val = temp->data;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;

  --length;

  return val;
}

/*********************************************
 * display all nodes
 ********************************************/
void CDlist::print() 
{
  if (length == 0) 
  {
    cout << "List is empty..." << endl;
    return;
  }
  Node *temp = head;

  for(int i=0; i<length; ++i)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}
