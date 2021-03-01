/**
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
 * Runtime: 12 ms, faster than 88.39%
 * Memory Usage: 7.5 MB, less than 83.80%
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
