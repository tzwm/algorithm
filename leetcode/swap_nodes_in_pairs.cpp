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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        ListNode *i = head->next;
        ListNode *last = head;
        last->next = i->next;
        i->next  = last;
        head = i;
        i = last->next;
        
        while(i != NULL && i->next != NULL) {
            ListNode *tmp = i->next;
            i->next = tmp->next;
            tmp->next = i;
            last->next = tmp;
            i = i->next;
            last = last->next->next;
        }
        
        return head;
    }
};

