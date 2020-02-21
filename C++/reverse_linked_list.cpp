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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        ListNode* stack = NULL;
        ListNode* newNode;
        ListNode* current = head;
        
        stack = new ListNode(current->val);
        current = current->next;
            
        while(current != NULL){
            newNode = new ListNode(current->val);
            newNode->next = stack;
            stack = newNode;
            
            current = current->next;
        }
        
        return stack;
    }
};