/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* tmp = head;
    struct ListNode* result = head;
    int N;
    for(N=0; tmp != NULL; N++)
        tmp = tmp->next;
    int i;
    for(i=0; i<N/2; i++)
        result = result->next; 
    return result;
}
