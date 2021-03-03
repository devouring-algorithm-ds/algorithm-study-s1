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

  return 0;
}
