#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

template <class T> 
class Node 
{
  public:
    T data;
    Node<T> *next;

    Node<T>() : next(nullptr) { ; }
    Node<T>(T data) : data(data), next(nullptr) { ; }
};

template <class T>
class Stack
{
  private:
    Node<T> *top;
    int length;

  public:
    Stack<T>() : top(nullptr), length(0) { ; }
    Stack<T>(T data) : top(new Node<T>(data)), length(1) { ; }
    ~Stack<T>();

    void push(T data);
    T pop();
    T peek();
    bool isEmpty() { return length == 0; }
    void print();
};

  template <class T>
void Stack<T>::push(T data)
{
  if (top == nullptr) 
  {
    top = new Node<T>(data);
  }
  else
  {
    Node<T> *temp = new Node<T>(data);
    temp->next = top;
    top = temp;
  }

  ++length;
}

  template <class T>
T Stack<T>::pop() 
{
  if (top == nullptr)
  {
    cerr << "pop() -- Stack is empty..." << endl;
    return static_cast<T>(NULL);
  }
  else 
  {
    T data = top->data;
    Node<T> *temp = top->next;
    delete top;
    top = temp;
    --length;

    return data;
  }
}

  template <class T>
T Stack<T>::peek() 
{
  if(top) return top->data;
  else 
  {
    cerr << "peek() -- Stack is empty..." << endl;
    return static_cast<T>(NULL);
  }
}

  template <class T>
Stack<T>::~Stack<T>()
{
  cout << "destructor called ..." << endl;
  for(int i=0; i<length; ++i)
  {
    Node<T> *temp = top->next;
    cout << "removed " << top->data << endl;
    delete top;
    top = temp;
  }

  if (top) delete top;
  top = nullptr; 
  length = 0;
  cout << "destructor finished ..." << endl; 
}

  template <class T> 
void Stack<T>::print()
{
  if(length == 0) 
  {
    cerr << "print() -- Stack is empty..." << endl;
    return ;
  }

  cout << "print: ";
  Node<T> *temp = top;
  for(int i=0; i<length; ++i)
  {
    cout << temp->data <<  ' ';
    temp = temp->next;
  }
  cout << endl;
}
