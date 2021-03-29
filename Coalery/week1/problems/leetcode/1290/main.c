/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int N;
int vals[30];

int getDecimalValue(struct ListNode* head){
    struct ListNode* tmp = head;
    for(N=0; tmp != NULL; N++) {
        vals[N] = tmp->val;
        tmp = tmp->next;
    }
    
    int result = 0;
    int i;
    for(i=0; i<N; i++)
        result += vals[i] << N - i - 1;
    return result;
}
