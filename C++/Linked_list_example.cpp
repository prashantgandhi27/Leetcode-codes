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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int unit_digit = 0;
        int tens_digit = 0;
        ListNode* p;
        ListNode* head;
        head = NULL;
        p = NULL;
        while((l1 != NULL) || (l2 != NULL))
        {
            if((l1 == NULL) && (l2 != NULL)){
                sum = l2->val + tens_digit;

            }else if((l1 != NULL) && (l2 == NULL)){
                sum = l1->val + tens_digit;

            }else{
                sum = l1->val + l2->val + tens_digit;

            }

                if(sum > 9){
                    tens_digit = sum / 10;
                    unit_digit = sum % 10;
                }else{
                    unit_digit = sum;
                    tens_digit=0;
                }
            ListNode* newnode;
            newnode = new ListNode(unit_digit);
            newnode->next = NULL;

                if(head == NULL){
                    head = newnode;
                    p = newnode;
                }else{
                    p->next = newnode;
                    p = newnode;
                }

            if((l1 == NULL) && (l2 != NULL)){
                l2 = l2->next;
            }else if((l1 != NULL) && (l2 == NULL)){
                l1 = l1->next;
            }else{
                l1 = l1->next;
                l2 = l2->next;
            }

        }

        if((l1 != NULL) && (l2 == NULL)){
            sum = l1->val + tens_digit;
            if(sum > 9){
                    tens_digit = sum / 10;
                    unit_digit = sum % 10;
                }else{
                    unit_digit = sum;
                    tens_digit=0;
                }
            ListNode* newnode;
            newnode = new ListNode(unit_digit);
            newnode->next = NULL;
            p->next = newnode;
            p = newnode;
        }else  if((l1 == NULL) && (l2 != NULL)){
            sum = l2->val + tens_digit;
            if(sum > 9){
                    tens_digit = sum / 10;
                    unit_digit = sum % 10;
                }else{
                    unit_digit = sum;
                    tens_digit=0;
                }
            ListNode* newnode;
            newnode = new ListNode(unit_digit);
            newnode->next = NULL;
            p->next = newnode;
            p = newnode;
        }

        if(tens_digit != 0){
            ListNode* newnode;
            newnode = new ListNode(tens_digit);
            newnode->next = NULL;
            p->next = newnode;
            p = newnode;
        }
        return head;
    }
};
