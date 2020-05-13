/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* current = head;
    struct ListNode* prev_current = head;
    
    if(head == NULL) return NULL;
    
    while((head->val == val) && (head->next != NULL))
    {
        head = head->next;
        current = head;
        prev_current = head;
    }
    
    if(head->val == val) return NULL;
    
    while(current != NULL)
    {
        if((current->val == val)) {
            prev_current->next = current->next;
            current = prev_current;
        }
        
        if(prev_current == current) {
            current = current->next;
        }else {
            prev_current = prev_current->next;
            current = current->next;
        }
    }
    return head;
}