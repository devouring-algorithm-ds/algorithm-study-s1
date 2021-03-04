#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class Node
{
public:
  Node<T>* next;
  T data;

	Node(T val_in = 10000 )
	{
		next = NULL;
		data = val_in; 
	}
};

template <typename T>
class LinkedList
{
	//pointer
	Node<T>* head;
	Node<T>* tail;

	//Node obj pointer
	Node<T>* newNode;
public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		delete head;
	}
	void insertFront(T val_in);
	void insertLast(T val_in);
	void removeFront();
	void removeLast();
  void printList();
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
  if(head == NULL) //At first, there is 0 element.
  {
    insertFront(val_in);
  }
  else
  {
    newNode = new Node<T>(val_in);
    Node<T>* temp = head;
    while(temp -> next != NULL)
    {
      temp = temp -> next; 
    }
    temp -> next = newNode;
  }
}

template <typename T>
void LinkedList<T>::removeFront()
{
  Node<T>* temp = head -> next;
  delete head;
  head = temp;
}

template <typename T>
void LinkedList<T>::removeLast()
{
  Node<T>* temp = head;
  if(temp -> next == NULL)//At the end, there is only 1 element.
  {
    removeFront();
  }
  else
  {
    while((temp -> next) -> next != NULL)
    {
      temp = temp -> next;
    }
    Node<T>* tail = temp -> next;
    delete tail;
    temp -> next = NULL;
  } 
}

template <typename T>
void LinkedList<T>::printList()
{
  Node<T>* temp = head;
  if(temp == NULL)
  {
    std::cout << "empty list";
  }
  else
  {
    while(temp -> next != NULL)
    {
      std::cout << (temp -> data);
      temp = temp -> next;
    }
    std::cout << (temp -> data);
  }
  std::cout << std::endl;
}





#endif
