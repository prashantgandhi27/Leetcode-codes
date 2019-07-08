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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* current_1=NULL;
        ListNode* current_2=NULL;
        ListNode* count_node_1=NULL;
        ListNode* count_node_2=NULL;
        ListNode* prevTail_1=NULL;
        ListNode* prevTail_2=NULL;
        ListNode* first_node=NULL;
        ListNode* new_node=NULL;
        int count_1=0,count_2=0,count_dec=0,prev_count=0;
        current_1 = l1;
        current_2 = l2;
        count_node_1 = l1;
        count_node_2 = l2;
        while(count_node_1!=NULL){
            count_1++;
            count_node_1 = count_node_1->next;
        }
        while(count_node_2!=NULL){
            count_2++;
            count_node_2 = count_node_2->next;
        }
        
        if(count_1 > count_2){
            if(count_2 == 0){
                first_node = l1;
            }else{
                first_node = l1;
                prevTail_1 = l1;
                count_dec = count_2;
                for(int i=0;i<count_2;i++){
                    prev_count = count_dec;
                    current_1 = first_node;
                    prevTail_1 = first_node;
                    while(current_1 != NULL){
                        if(current_2->val <= current_1->val){
                            if(prevTail_1 == current_1){
                                new_node = new ListNode(current_2->val);
                                new_node->next = prevTail_1;
                                prevTail_1 = new_node;
                                first_node = prevTail_1;
                                count_dec--;
                                break;
                            }else{
                                new_node = new ListNode(current_2->val);
                                new_node->next = prevTail_1->next;
                                prevTail_1->next = new_node;
                                count_dec--;
                                break;
                            }
                        }else{
                            if(prevTail_1 == current_1){
                                current_1 = current_1->next;
                            }else{
                                prevTail_1 = prevTail_1->next;
                                current_1 = current_1->next;
                            }
                        }
                    }
                    if(prev_count > count_dec){
                        current_2 = current_2->next;
                    }else if(prev_count == count_dec){
                        prevTail_1->next = current_2;
                        break;
                    }
                      
                }
            }
        }else if(count_1 < count_2){
                if(count_1 == 0){
                first_node = l2;
            }else{
                first_node = l2;
                prevTail_2 = l2;
                count_dec = count_1;
                for(int i=0;i<count_1;i++){
                    prev_count = count_dec;
                    current_2 = first_node;
                    prevTail_2 = first_node;
                    while(current_2 != NULL){
                        if(current_1->val <= current_2->val){
                            if(prevTail_2 == current_2){
                                new_node = new ListNode(current_1->val);
                                new_node->next = prevTail_2;
                                prevTail_2 = new_node;
                                first_node = prevTail_2;
                                count_dec--;
                                break;
                            }else{
                                new_node = new ListNode(current_1->val);
                                new_node->next = prevTail_2->next;
                                prevTail_2->next = new_node;
                                count_dec--;
                                break;
                            }
                        }else{
                            if(prevTail_2 == current_2){
                                current_2 = current_2->next;
                            }else{
                                prevTail_2 = prevTail_2->next;
                                current_2 = current_2->next;
                            }
                        }
                    }
                    if(prev_count > count_dec){
                        current_1 = current_1->next;
                    }else if(prev_count == count_dec){
                        prevTail_2->next = current_1;
                        break;
                    }
                      
                }
            }
        }else if(count_1 = count_2){
            if(count_2 == 0){
                first_node = l1;
            }else if(count_1 == 0){
                first_node = l2;
            }else{
                first_node = l1;
                prevTail_1 = l1;
                count_dec = count_2;
                for(int i=0;i<count_2;i++){
                    prev_count = count_dec;
                    current_1 = first_node;
                    prevTail_1 = first_node;
                    while(current_1 != NULL){
                        if(current_2->val <= current_1->val){
                            if(prevTail_1 == current_1){
                                new_node = new ListNode(current_2->val);
                                new_node->next = prevTail_1;
                                prevTail_1 = new_node;
                                first_node = prevTail_1;
                                count_dec--;
                                break;
                            }else{
                                new_node = new ListNode(current_2->val);
                                new_node->next = current_1;
                                prevTail_1->next = new_node;
                                count_dec--;
                                break;
                            }
                        }else{
                            if(prevTail_1 == current_1){
                                current_1 = current_1->next;
                            }else{
                                prevTail_1 = prevTail_1->next;
                                current_1 = current_1->next;
                            }
                        }
                    }
                    if(prev_count > count_dec){
                        current_2 = current_2->next;
                    }else if(prev_count == count_dec){
                        prevTail_1->next = current_2;
                        break;
                    }
                      
                }
            }
        }
        
        return first_node;
    }
};