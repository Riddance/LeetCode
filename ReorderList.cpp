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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode dummy_node(0);
        dummy_node.next = head;
        ListNode *slow = NULL;
        ListNode *fast = NULL;
        slow = fast = &dummy_node;

        while (slow && fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //only one node
        if (slow == fast)
            return;

        //now we have two lists:list_lhs and list_rhs
        ListNode *list_lhs = dummy_node.next;
        ListNode *list_rhs = slow->next;
        slow->next = NULL;

        //reverse list_rhs
        {
            ListNode dummy_node(0);
            while (list_rhs) {
                ListNode *temp = list_rhs->next;
                list_rhs->next = dummy_node.next;
                dummy_node.next = list_rhs;
                list_rhs = temp;
            }
            list_rhs = dummy_node.next;
        }

        //merge list_rhs and list_lhs to dummy_node

        ListNode *cur_node = &dummy_node;
        dummy_node.next = NULL;

        while (list_lhs && list_rhs) {
            cur_node->next = list_lhs;
            cur_node = cur_node->next;
            list_lhs = list_lhs->next;

            cur_node->next = list_rhs;
            cur_node = cur_node->next;
            list_rhs = list_rhs->next;
        }

        if (list_lhs) cur_node->next = list_lhs;
        if (list_rhs) cur_node->next = list_rhs;

        head = dummy_node.next;
        return;
    }
};
