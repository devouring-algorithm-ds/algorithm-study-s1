#include <iostream>

using namespace std;

#include "slist.hpp"

int main() 
{
  Slist list;

  for(int i=1; i<=5; ++i)
  {
    cout << "insertFront(" << i << ")\n";
    list.insertFront(i);
  }
  list.print();
  cout << endl;

  for(int i=6; i<=10; ++i)
  {
    cout << "insertBack(" << i << ")\n";
    list.insertBack(i);
  }
  list.print();
  cout << endl;

  cout << "removeLast -> Removed " << list.removeLast() << endl;
  cout << "removeFirst -> Removed " << list.removeFirst() << endl;
  cout << "removeLast -> Removed " << list.removeLast() << endl;
  cout << "removeFirst -> Removed " << list.removeFirst() << endl;
  list.print();
  cout << endl;

  cout << "InsertAt(100, 1) -> insert 100 at index 1" << endl;
  list.insertAt(100, 1);
  list.print();

  cout << "InsertAt(200, 0) -> insert 200 at index 0" << endl;
  list.insertAt(200, 0);
  list.print();
  cout << endl;

  cout << "while the list is not empty ... " << endl;
  while(!list.isEmpty()) 
    cout << "removeFirst -> Removed " << list.removeFirst() << endl;
  list.print();
  cout << endl;

  cout << "InsertAt(1, 10) -> insert 1 at index 10" << endl;
  list.insertAt(1, 10);
  list.print();
  cout << "InsertAt(2, 10) -> insert 2 at index 10" << endl;
  list.insertAt(2, 10);
  list.print();
  cout << "InsertAt(3, 0) -> insert 3 at index 0" << endl;
  list.insertAt(3, 0);
  list.print();
  cout << "InsertAt(4, -1) -> insert 4 at index -1" << endl;
  list.insertAt(4, -1);
  list.print();
  cout << endl;

  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();
  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();
  cout << "removeAt(5): " << list.removeAt(5) << endl;
  list.print();
  cout << "removeAt(-1): " << list.removeAt(-1) << endl;
  list.print();
  cout << endl;


  cout << "insertFront(100)" << endl;
  list.insertFront(100);
  list.print();

  cout << "insertBack(200)" << endl;
  list.insertBack(200);
  list.print();

  cout << "InsertAt(300, 1)" << endl;
  list.insertAt(300, 1);
  list.print();

  cout << "removeFirst -> Removed " << list.removeFirst() << endl;
  list.print();
  cout << "removeLast -> Removed " << list.removeLast() << endl;
  list.print();
  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();

  return 0;
}
