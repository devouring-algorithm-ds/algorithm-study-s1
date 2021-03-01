// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        unsigned long result = 0;
        
        while (true)
        {
            result = (result << 1) + head->val;
            head = head->next;
            
            if (head == NULL || head == nullptr) break;
        }
        
        return result;
    }
};
