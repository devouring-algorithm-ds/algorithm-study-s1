#include <iostream>
#include <cstring>

using namespace std;

#include "stack.hpp"

int main()
{
  //////////////////////////////////// stack<int>
  Stack<int> *numbers = new Stack<int>();
  string expr;

  getline(cin, expr);

  for(size_t i=0; i<expr.size(); ++i) {
    if(isdigit(expr[i])) {
      numbers->push(expr[i]-'0');
    } else if(expr[i] == ' ') {
      continue;
    } else {
      int a = numbers->pop();
      int b = numbers->pop();

      cout << "a: " << a << ' ' << "b: " << b << endl;

      switch(expr[i]) {
        case '+':
          numbers->push(b+a);
          break;
        case '-':
          numbers->push(b-a);
          break;
        case '/':
          numbers->push(b/a);
          break;
        case '*':
          numbers->push(b*a);
          break;
      }
    }
  }

  cout << "Result: " << numbers->pop() << endl;
  delete numbers;

  return 0;
}
