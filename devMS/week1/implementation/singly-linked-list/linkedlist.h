#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class Node
{
public:
  Node<T>* next;
  T data;

	Node(T val_in = 0 )
	{
		next = nullptr;
		data = val_in; 
	}
};

template <typename T>
class LinkedList
{
	//Head pointer
	Node<T>* head;

	//New Node obj pointer
	Node<T>* newNode;
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList()
	{
		removeAll();
	}
	void insertFront(T val_in);
	void insertLast(T val_in);
	void removeFront();
	void removeLast();
    	void printList();
    	void removeAll();
};

template <typename T>
void LinkedList<T>::insertFront(T val_in)
{
  newNode = new Node<T>(val_in);
  newNode -> next = head;
  head = newNode;
}

template <typename T>
void LinkedList<T>::insertLast(T val_in)
{
  if(head == nullptr) //At first, there is 0 element.
  {
    insertFront(val_in);
  }
  else
  {
    newNode = new Node<T>(val_in);
    Node<T>* temp = head;
    while(temp -> next != nullptr)
    {
      temp = temp -> next; 
    }
    temp -> next = newNode;
  }
}

template <typename T>
void LinkedList<T>::removeFront()
{
  if(head == nullptr)
  {
    std::cout<<"Can't remove:List is empty." << std::endl;
    return;
  }
  Node<T>* temp = head -> next;
  delete head;
  head = temp;
}

template <typename T>
void LinkedList<T>::removeLast()
{
  if(head == nullptr)
  {
    std::cout<<"Can't remove:List is empty." << std::endl;
    return;
  }
  Node<T>* temp = head;
  if(temp -> next == nullptr)//At the end, there is only 1 element.
  {
    removeFront();
  }
  else
  {
    while((temp -> next) -> next != nullptr)
    {
      temp = temp -> next;
    }
    Node<T>* tail = temp -> next;
    delete tail;
    temp -> next = nullptr;
  } 
}
template <typename T>
void LinkedList<T>::removeAll()
{
  if(head == nullptr)
  {
    std::cout << "List is already empty." << std::endl;
  }
  else
  {
    while(head -> next != nullptr)
    {
      removeFront();
    }
    removeFront();//At the end, there is only 1 element.
    std::cout << "Remove all" << std::endl;
  }
}

template <typename T>
void LinkedList<T>::printList()
{
  if(head == nullptr)
  {
    std::cout << "Can't print:List is empty." << std::endl;
    return;
  }
  Node<T>* temp = head;
  while(temp -> next != nullptr)
  {
    std::cout << (temp -> data);
    temp = temp -> next;
  }
  std::cout << (temp -> data);
  std::cout << std::endl;
}





#endif
