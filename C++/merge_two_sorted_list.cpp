/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;

    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* current = NULL;
    struct ListNode* head = NULL;

    while((temp1 != NULL) && (temp2 != NULL))
    {
        if(temp1->val == temp2->val)
        {
            if(head == NULL)
            {
                current = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->val = temp1->val;
                current->next = NULL;
                head = current;
                current->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->next->val = temp2->val;
                current->next->next = NULL;
                current = current->next;
            }else{
                current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->next->val = temp1->val;
                current->next->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->next->next->val = temp2->val;
                current->next->next->next = NULL;
                current = current->next->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if(temp1->val < temp2->val) {
            if(head == NULL)
            {
                current = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->val = temp1->val;
                current->next = NULL;
                head = current;
            }else{
                current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->next->val = temp1->val;
                current->next->next  = NULL;
                current = current->next;
            }
            temp1 = temp1->next;
        }else {
            if(head == NULL)
            {
                current = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->val = temp2->val;
                current->next = NULL;
                head = current;
            }else{
                current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                current->next->val = temp2->val;
                current->next->next = NULL;
                current = current->next;
            }
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL)
    {
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current->next->val = temp1->val;
        current->next->next  = NULL;
        current = current->next;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current->next->val = temp2->val;
        current->next->next  = NULL;
        current = current->next;
        temp2 = temp2->next;
    }

    return head;
}
