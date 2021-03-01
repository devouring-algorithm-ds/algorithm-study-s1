/*
 * https://leetcode.com/problems/middle-of-the-linked-list/
 * Runtime: 0 ms, faster than 100.00% 
 * Memory Usage: 6.6 MB, less than 77.42%
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp) {
            ++cnt;
            temp = temp->next;
        }
        
        cnt >>= 1;
        temp = head;
        while(cnt--) temp = temp->next;
        
        return temp;
    }
};
