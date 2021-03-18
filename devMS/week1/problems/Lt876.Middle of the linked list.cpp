/*
Leetcode 876. Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/
*/
#include<iostream>
//#include<vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* list[100];
        int cnt = 0;
        int size = 0;
        ListNode* temp = head; // temp is iterator.
        while (temp->next != nullptr)
        {
            list[cnt] = temp;
            temp = temp->next;
            cnt++;
        }
        list[cnt] = temp;

        size = cnt + 1;
        return list[size / 2];
    }
};

//class Solution {
//public:
//    ListNode* middleNode(ListNode* head) 
//    {
//        vector<ListNode*> A = { head };
//        while (A.back()->next != NULL)
//        {
//            A.push_back(A.back()->next);
//        }
//        return A[A.size() / 2];
//    }
//};
