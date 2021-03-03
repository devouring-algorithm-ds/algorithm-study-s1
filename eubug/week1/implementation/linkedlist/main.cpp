#include <iostream>

using namespace std;

#include "slist.hpp"

int main() 
{
  Slist list;

  for(int i=1; i<=5; ++i)
    list.insertFront(i);
  list.print();

  for(int i=6; i<=10; ++i)
    list.insertBack(i);
  list.print();

  cout << "removeLast: " << list.removeLast() << endl;
  cout << "removeFirst: " << list.removeFirst() << endl;
  cout << "removeLast: " << list.removeLast() << endl;
  cout << "removeFirst: " << list.removeFirst() << endl;

  list.print();

  list.insertAt(100, 1);
  list.print();

  list.insertAt(200, 0);
  list.print();

  while(!list.isEmpty()) 
    cout << "removeFirst: " << list.removeFirst() << endl;

  list.print();

  list.insertAt(1, 10);
  list.insertAt(2, 10);
  list.insertAt(3, 0);
  list.insertAt(4, -1);

  list.print();

  return 0;
}
