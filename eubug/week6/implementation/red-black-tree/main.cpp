#include <cstdio>
#include <iostream>
#include "RedBlackTree.hpp"
using namespace std;

int main(){
  char cmd;
  int number;
  RedBlackTree rbtree;

#if 0
  while (cin >> cmd >> number){
		if (cmd == 'x') break;

		if (cmd == 'i'){
			cout << "Insert " << number << '\n';
			rbtree.Insert(number);
		}
    else if (cmd == 'o') {
      cout << "Inorder print: ";
      rbtree.Inorder();
      cout << endl;
    }
		else if {
			cout << "Delete " << number << '\n';
			rbtree.Delete(number);
		}
		// print for debug
		rbtree.Print();
	}
#endif 

  cin >> number;
  for(int i=0; i<number; ++i) {
    int temp;
    cin >> temp;
    rbtree.Insert(temp);
    cout << "-------------- inorder ----------------" << endl;
    rbtree.Inorder();
    cout << "-------------- graph ----------------" << endl;
    rbtree.Print();
    cout << endl;
  }

  cin >> number;
  for(int i=0; i<number; ++i) {
    int temp; 
    cin >> temp;
    cout << rbtree.Find(temp) << endl;
  }

  return 0;
}
