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
        ListNode *new_head = NULL;

        bool need_remove = false;

        cur_node = head;

        while (cur_node) {
            if (cur_node->next && cur_node->val == (cur_node->next)->val) {
                cur_node = cur_node->next;
                need_remove = true;
                continue;
            }

            if (need_remove && pre_node) {
                pre_node->next = cur_node->next;
                need_remove = false;
                cur_node = cur_node->next;
                continue;
            }
            
            if (need_remove) {
                cur_node = cur_node->next;
                need_remove = false;
                continue;
            }

            if (!new_head) {
                if (need_remove) new_head = cur_node->next;
                else new_head = cur_node;
            }

            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        return new_head;
    }
};
