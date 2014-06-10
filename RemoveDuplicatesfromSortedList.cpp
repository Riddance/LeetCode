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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *cur_node = NULL;
        ListNode *pre_node = NULL;

        if (!head) return head;

        pre_node = head;
        cur_node = head->next;

        while (cur_node) {
            if (cur_node->val == pre_node->val) {
                pre_node->next = cur_node->next;
                cur_node = cur_node->next;
                continue;
            }

            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        return head;
    }
};