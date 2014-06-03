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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode dummy_node(0);

        ListNode *travel_node = head;

        while (travel_node) {
            ListNode *insert_pos = &dummy_node;
            
            while (insert_pos->next && insert_pos->next->val < travel_node->val)
                insert_pos = insert_pos->next;

            ListNode *next_node = travel_node->next;

            travel_node->next = insert_pos->next;
            insert_pos->next = travel_node;

            travel_node = next_node;
        }

        return dummy_node.next;
    }
};
