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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode dummy_node(0);
        ListNode* cur = NULL;

        cur = &dummy_node;
        while (l1 || l2) {
            if (l1 == NULL) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
                continue;
            }

            if (l2 == NULL) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
                continue;
            }

            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
                continue;
            }

            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }

        return dummy_node.next;
    }
};
