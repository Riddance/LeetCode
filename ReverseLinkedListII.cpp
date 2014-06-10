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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *reverse_begin = NULL;
        ListNode *reverse_end   = NULL;
        ListNode *reverse_prev  = NULL;
        int      diff           = 0;

        diff = n - m;
        reverse_begin = reverse_end = head;

        if (diff == 0) return head;

        while (diff > 0) {
            reverse_end = reverse_end->next;
            --diff;
        }

        while (m > 1) {
            reverse_prev = reverse_begin;
            reverse_begin = reverse_begin->next;
            reverse_end = reverse_end->next;
            --m;
        }

        //reverse nodes from begin to end
        ListNode *pre_node = reverse_begin;
        ListNode *cur_node = reverse_begin->next;

        while (cur_node != reverse_end) {
            ListNode *temp = cur_node->next;
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = temp;
        }

        reverse_begin->next = cur_node->next;
        cur_node->next = pre_node;

        if (!reverse_prev) head = reverse_end;
        else reverse_prev->next = reverse_end;

        return head;
    }
};
