/*
* 백준: 요세푸스 문제 
* https://www.acmicpc.net/problem/1158
*/

#include <iostream>
#include "circular_linkedlist.h"

using namespace std;

int main()
{
    LinkedList<int> list;
    Node<int>* searchNode = list.front();

    int total_num;
    int kill_num;

    //Input handling
    cin >> total_num;
    cin >> kill_num;

    //Generating list from the input
    for (int i = 1; i <= total_num; i++) {
        list.push_back(i);
    }
    
    //Searching victim to kill
    while (!list.empty())
    {
        kill_nth(kill_num);
    }
    


    

    /*while (!list.empty()) {
        cout << l.front() << ' ';
        list.pop_front();
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
    double_list.pop_back();*/

}

void kill_nth(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        searchNode = (searchNode->next);
        while ((searchNode == list.head) || (searchNode == list.tail))
        {
            searchNode = (searchNode->next);
        }   
    }
    searchNode = (searchNode->next);
    list.erase(searchNode -> prev);
    cout << (searchNode->val) << ",";
    
}
