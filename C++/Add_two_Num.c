/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    int carry = 0, sum=0;
    
    struct ListNode* current1 = l1;
    struct ListNode* current2 = l2;
    struct ListNode* result = NULL;
    struct ListNode* newNode = NULL;
    struct ListNode* temp = NULL;
    
    while((current1 != NULL)&&(current2 != NULL))
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        
        if(result == NULL)
        {
            result = newNode;
            temp = newNode;
        }else {
            temp->next = newNode;
            temp = temp->next;
        }
            
        if(0 == carry)
        {
            sum = current1->val + current2->val;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            newNode->val = sum;
        }else {
            sum = current1->val + current2->val + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }else {
                carry = 0;
            }
            newNode->val = sum;
        }
        
        current1 = current1->next;
        current2 = current2->next;
    }
    
    while(current1 != NULL)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = temp->next;
            
        if(0 == carry)
        {
            sum = current1->val ;
            newNode->val = sum;
        }else {
            sum = current1->val +  carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }else {
                carry = 0;
            }
            newNode->val = sum;
        }
        
        current1 = current1->next;
    }
    
    while(current2 != NULL)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = temp->next;
            
        if(0 == carry)
        {
            sum = current2->val ;
            newNode->val = sum;
        }else {
            sum = current2->val +  carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }else {
                carry = 0;
            }
            newNode->val = sum;
        }
        
        current2 = current2->next;
    }
    
    if(carry != 0)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = temp->next;
        
        newNode->val = carry;
    }
    
    return result;
}