/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = NULL;
        ListNode* temp = NULL;
        current = head;
        temp = head;
        while(current!=NULL){
            if(current->next != NULL){
                if(current->val == current->next->val){
                    temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    temp = current;
                }else{
                    current = current->next;
                    temp = current;
                }
            }else{
                    current = current->next;
                    temp = current;
            }
        }
      return head;
    }
};
