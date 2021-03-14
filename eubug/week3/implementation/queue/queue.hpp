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
class Queue
{
  private:
    Node<T> *front;
    Node<T> *back;
    int length;

  public:
    Queue<T>() : front(nullptr), back(nullptr), length(0) { ; }
    Queue<T>(T data) 
    {
      front = new Node<T>(data);
      back = front;
      length = 1;
    }

    ~Queue<T>();

    void enqueue(T data);
    T dequeue();

    T getFront();
    T getBack();

    bool isEmpty() { return length == 0; }
    void print();
};

  template <class T>
void Queue<T>::enqueue(T data)
{
  if (front == nullptr) 
  {
    front = new Node<T>(data);
    back = front;
  }
  else
  {
    back->next = new Node<T>(data);
    back = back->next;
  }

  ++length;
}

  template <class T>
T Queue<T>::dequeue() 
{
  if (front == nullptr)
  {
    cerr << "dequeue() -- Queue is empty..." << endl;
    return static_cast<T>(NULL);
  }
  else 
  {
    T data = front->data;
    Node<T> *temp = front->next;
    delete front;
    front = temp;
    --length;

    return data;
  }
}

template <class T>
T Queue<T>::getFront() 
{
  if(front) return front->data;
  else 
  {
    cerr << "getFront() -- Queue is empty..." << endl;
    return static_cast<T>(NULL);
  }
}

template <class T>
T Queue<T>::getBack() 
{
  if(back) return back->data;
  else 
  {
    cerr << "getBack() -- Queue is empty..." << endl;
    return static_cast<T>(NULL);
  }
}
  template <class T>
Queue<T>::~Queue<T>()
{
  cout << "destructor called ..." << endl;
  for(int i=0; i<length; ++i)
  {
    Node<T> *temp = front->next;
    cout << "removed " << front->data << endl;
    delete front;
    front = temp;
  }

  if (front) delete front;
  if (back) delete front;
  front = back = nullptr; 
  length = 0;
  cout << "destructor finished ..." << endl; 
}

  template <class T> 
void Queue<T>::print()
{
  if(length == 0) 
  {
    cerr << "print() -- Queue is empty..." << endl;
    return ;
  }

  cout << "print: ";
  Node<T> *temp = front;
  for(int i=0; i<length; ++i)
  {
    cout << temp->data <<  ' ';
    temp = temp->next;
  }
  cout << endl;
}
