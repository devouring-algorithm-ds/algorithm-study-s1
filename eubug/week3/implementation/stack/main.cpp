#include "stack.hpp"

int main()
{
  //////////////////////////////////// stack<int>
  Stack<int> *stack = new Stack<int>();

  cout << "Push 1, 2, and 3" << endl;
  stack->push(1);
  stack->push(2);
  stack->push(3);
  stack->print();
  cout << endl;

  cout << "Remove top" << endl;
  stack->pop();
  stack->print();
  cout << endl;

  cout << "Remove top" << endl;
  stack->pop();
  stack->print();
  cout << endl;

  cout << "Remove top" << endl;
  stack->pop();
  stack->print();
  cout << endl;

  cout << "Push 100 and 200" << endl;
  stack->push(100);
  stack->push(200);
  cout << endl;

  cout << "Remove top" << endl;
  stack->pop();
  stack->print();
  cout << endl;

  cout << "Push 500" << endl;
  stack->push(500);
  stack->print();
  cout << endl;

  delete stack;

  //////////////////////////////////// stack<char>
  cout << endl << "New Stack!!" << endl;
  Stack<char> *stack2 = new Stack<char>();
  cout << "Push 'a', 'b', and 'c'" << endl;
  stack2->push('a');
  stack2->push('b');
  stack2->push('c');
  stack2->print();

  cout << "Remove top" << endl;
  stack2->pop();
  stack2->print();

  cout << "Remove top" << endl;
  stack2->pop();
  stack2->print();

  cout << "Remove top" << endl;
  stack2->pop();
  stack2->print();

  cout << "Push 'Eubug'" << endl;
  stack2->push('E');
  stack2->push('u');
  stack2->push('b');
  stack2->push('u');
  stack2->push('g');
  stack2->print();
  delete stack2;

  return 0;
}
