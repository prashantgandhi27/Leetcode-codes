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
    struct ListNode* temp = NULL;
    if(head == NULL) return NULL;
    
    while((head->val == val) && (head->next != NULL))
    {
        temp = head;
        head = head->next;
        current = head;
        prev_current = head;
        free(temp);
    }
    
    if(head->val == val) return NULL;
    
    while(current != NULL)
    {
        if((current->val == val)) {
            temp = current;
            prev_current->next = current->next;
            current = prev_current;
            free(temp);
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