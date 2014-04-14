//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int num = 0;
        ListNode *root = new ListNode(-1);
        ListNode *r = root;
        root->next = r;
        while(l1 != NULL){
            int a = l1->val;
            l1 = l1->next;
            int b = 0;
            if(l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            int c = a + b + num;
            num = c / 10;
            c = c % 10;
            ListNode *node = new ListNode(c);
            r->next = node;
            r = r->next;
        }
        while(l2 != NULL) {
            int a = l2->val;
            l2 = l2->next;
            int c = a + num;
            num = c / 10;
            c = c % 10;
            ListNode *node = new ListNode(c);
            r->next = node;
            r = r->next;
        }
        if(num != 0) {
            ListNode *node = new ListNode(num);
            r->next = node;
            r = r->next;
        }
        
        return root->next;
    }
};

