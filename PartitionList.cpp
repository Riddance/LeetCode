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
    ListNode *partition(ListNode *head, int x) {
        ListNode *lhead = NULL;
        ListNode *ltail = NULL;

        ListNode *rhead = NULL;
        ListNode *rtail = NULL;

        while (head) {
            if (head->val < x) {

                if (lhead == NULL) lhead = ltail = head;
                else {
                    ltail->next = head;
                    ltail = ltail->next;
                }

                head = head->next;
                continue;
            }

            if (rhead == NULL) rhead = rtail = head;
            else {
                rtail->next = head;
                rtail = rtail->next;
            }

            head = head->next;
        }

        if (ltail) ltail->next = NULL;
        if (rtail) rtail->next = NULL;

        if (lhead) {
            ltail->next = rhead;
            return lhead;
        }

        return rhead;
    }
};
