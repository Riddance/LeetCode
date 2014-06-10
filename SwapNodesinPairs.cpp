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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *pre_node = NULL;
        ListNode *new_head = NULL;
        ListNode *cur_node = head;

        while (cur_node && cur_node->next) {
            if (pre_node) pre_node->next = cur_node->next;
            else new_head = cur_node->next;

            ListNode *temp = cur_node->next;
            cur_node->next = cur_node->next->next;
            temp->next = cur_node;
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        if (new_head == NULL) return head;
        else return new_head;   
    }
};