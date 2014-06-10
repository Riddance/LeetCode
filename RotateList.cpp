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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *begin_node    = NULL;
        ListNode *end_node      = NULL;
        ListNode *new_head      = NULL;
        int node_count          = 0;
        ListNode *cur_node      = head;
        
        while (cur_node) {
            cur_node = cur_node->next;
            node_count++;
        }
        
        if (node_count > 0)
            k = k % node_count;

        begin_node = end_node = head;

        while (k > 0 && end_node) {
            end_node = end_node->next;
            k--;
        }

        if (!end_node || k > 0)
            return head;

        while (end_node->next) {
            begin_node = begin_node->next;
            end_node = end_node->next;
        }
        
        if (begin_node == end_node) return head;

        new_head = begin_node->next;
        begin_node->next = NULL;
        end_node->next = head;

        return new_head;
    }
};
