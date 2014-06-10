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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *reverse_begin     = NULL;
        ListNode *reverse_end       = NULL;
        ListNode *new_head          = NULL;
        int count                   = 1;
        int need_reverse            = true;

        if (!head) return NULL;

        if (k <= 1) return head;

        reverse_begin = reverse_end = head;

        while (count < k && reverse_end) {
            reverse_end = reverse_end->next;
            ++count;
        }

        if (!reverse_end) need_reverse = false;

        if (need_reverse) new_head = reverse_end;
        else new_head = head;
        
        while (need_reverse) {
            ListNode *cur_node = reverse_begin;
            ListNode *pre_node = NULL;

            while (cur_node != reverse_end) {
                ListNode *temp = cur_node->next;
                cur_node->next = pre_node;
                pre_node = cur_node;
                cur_node = temp;
            }

            reverse_begin->next = cur_node->next;
            cur_node->next = pre_node;

            reverse_end = reverse_begin->next;

            count = 1;

            while (count < k && reverse_end) {
                reverse_end = reverse_end->next;
                ++count;
            }

            if (!reverse_end) need_reverse = false;

            if (need_reverse) {
                ListNode *temp = reverse_begin->next;
                reverse_begin->next = reverse_end;
                reverse_begin = temp;
            }
        }
        
        return new_head;
    }
};
