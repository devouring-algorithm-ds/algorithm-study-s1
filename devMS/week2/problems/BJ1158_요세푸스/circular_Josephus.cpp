/*
* 백준: 요세푸스 문제 
* https://www.acmicpc.net/problem/1158
*/

#include <iostream>
#include "circular_linkedlist.h"

using namespace std;

Node<int>* kill_nth(int n, LinkedList<int>& list, Node<int>* searchNode);
Node<int>* passDummy(LinkedList<int>& list, Node<int>* searchNode);

int main()
{
    LinkedList<int> list;
    Node<int>* searchNode;//Point to victim's next 

    int total_num;
    int kill_num;

    //Input handling
    cin >> total_num;
    cin >> kill_num;

    //Generating list from the input
    for (int i = 1; i <= total_num; i++) {
        list.push_back(i);
    }

    searchNode = list.head->next;
    
    cout << "<";
    //Searching victim to kill
    while (!list.empty())
    {
        searchNode = kill_nth(kill_num,list,searchNode);
    }
    cout << ">";

    return 0;


}
/*
* kill nth node
*/
Node<int>* kill_nth(int n, LinkedList<int>& list, Node<int>* searchNode)
{
    Node<int>* victimNode;// target that will be killed.

    for (int i = 0; i < n - 1; i++)
    {
        searchNode = (searchNode->next);
        searchNode = passDummy(list, searchNode);
    }
    
    searchNode = (searchNode->next);
    victimNode = searchNode->prev;
        
    cout << victimNode -> data;
    list.erase(victimNode);

    if (!list.empty()) //list가 비어있으면 dummy만 남아있어서 passDummy를 돌리면 무한루프가 된다.
    {
        searchNode = passDummy(list, searchNode);
        cout << ", ";
    }
  
    return searchNode;
    
}

/*
* Pass Dummy part: head and tail node
*/
Node<int>* passDummy(LinkedList<int>& list, Node<int>* searchNode) 
{
    while ((searchNode == list.head) || (searchNode == list.tail))
    {
        searchNode = (searchNode->next);
    }
    return searchNode;
}
