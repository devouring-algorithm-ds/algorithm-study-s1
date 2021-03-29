#include <iostream>
#include "circular_linkedlist.h"

using namespace std;

int main()
{
    // Step 1: Linked List
    LinkedList<int> l;

    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }

    while (!l.empty()) {
        cout << l.front() << ' ';
        l.pop_front();
    }
    cout << '\n';

    LinkedList<double> double_list;

    double_list.push_back(2.3);
    double_list.push_back(4.1);
    double_list.insert(double_list.find(2.3), 3.7);
    double_list.insert(double_list.find(2.3), 3.1);
    double_list.insert(double_list.find(4.1), 4.3);
    double_list.erase(double_list.find(4.1));

    cout << double_list.size() << '\n';

    while (!double_list.empty()) {
        cout << double_list.back() << ' ';
        double_list.pop_back();
    }
    double_list.pop_back();

}
