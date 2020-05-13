/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    bool palindrome = true;
    
    struct ListNode* current = head;
    struct ListNode* newNode = NULL;
    struct ListNode* rev_node = NULL;
    
    while(current != NULL)
    {
        if(rev_node == NULL)
        {
            newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = NULL;
            rev_node = newNode;
        }else{
            newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = rev_node;
            rev_node = newNode;
        }
        current = current->next;
    }
    
    current = head;
    
    while((current != NULL) && (rev_node != NULL))
    {
        if(current->val != rev_node->val)
            palindrome = false;
        
        current = current->next;
        rev_node = rev_node->next;
    }
    
    return palindrome;
}