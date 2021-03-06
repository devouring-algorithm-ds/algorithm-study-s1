#include <iostream>
#include "linkedlist.h"

using namespace std;
int main()
{
	LinkedList<int> list;
	list.insertLast(1); list.printList(); cout << "insertLast 1" << endl;
	list.insertFront(0); list.printList(); cout << "insertFront 0" << endl;
	list.insertLast(2); list.printList(); cout << "insertLast 2" << endl;
  	//list.removeFront(); list.printList(); cout << "removeFront" << endl;
  	//list.removeLast(); list.printList();  cout << "removeLast" << endl;
  	//list.removeLast(); list.printList(); cout << "removeLast" << endl;
  	//list.removeFront(); list.printList(); cout << "removeFront" << endl;
  
}

