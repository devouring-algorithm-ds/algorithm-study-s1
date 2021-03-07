#include <iostream>

#include "cdlist.hpp"

int main() 
{
  CDlist list;

#if 1
  for(int i=1; i<=5; ++i)
  {
    cout << "insertFront(" << i << ")\n";
    list.insertFront(i);
    list.print();
  }
  cout << endl;
#endif

#if 1
  for(int i=6; i<=10; ++i)
  {
    cout << "insertBack(" << i << ")\n";
    list.insertBack(i);
    list.print();
  }
  cout << endl;
#endif

#if 1
  cout << "removeBack -> Removed " << list.removeBack() << endl;
  cout << "removeFront -> Removed " << list.removeFront() << endl;
  cout << "removeBack -> Removed " << list.removeBack() << endl;
  cout << "removeFront -> Removed " << list.removeFront() << endl;
  list.print();
  cout << endl;
#endif

#if 1
  cout << "InsertAt(100, 1) -> insert 100 at index 1" << endl;
  list.insertAt(100, 1);
  list.print();

  cout << "InsertAt(200, 0) -> insert 200 at index 0" << endl;
  list.insertAt(200, 0);
  list.print();
  cout << endl;
#endif

#if 1
  cout << "while the list is not empty ... " << endl;
  while(!list.isEmpty()) 
    cout << "removeFront -> Removed " << list.removeFront() << endl;
  list.print();
  cout << endl;
#endif

#if 1
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
#endif

#if 1
  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();
  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();
  cout << "removeAt(5): " << list.removeAt(5) << endl;
  list.print();
  cout << "removeAt(-1): " << list.removeAt(-1) << endl;
  list.print();
  cout << endl;
#endif

#if 1
  cout << "removeFront -> Removed " << list.removeFront() << endl;
  cout << "removeFront -> Removed " << list.removeFront() << endl;

  cout << "insertFront(100)" << endl;
  list.insertFront(100);
  list.print();

  cout << "insertBack(200)" << endl;
  list.insertBack(200);
  list.print();
  cout << "InsertAt(300, 1)" << endl;
  list.insertAt(300, 1);
  list.print();

  cout << "removeFront -> Removed " << list.removeFront() << endl;
  list.print();
  cout << "removeBack -> Removed " << list.removeBack() << endl;
  list.print();
  cout << "removeAt(1): " << list.removeAt(1) << endl;
  list.print();
#endif

  return 0;
}
