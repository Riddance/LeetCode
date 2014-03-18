struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * A linked-list merge sort
 * Refer to TAOCP:
 * Donald E. Knuth. ``The Art of Computer Programming, Volume 3: Sorting and Searching (2nd Edition)''. 
 *    Addison-Wesley Professional; 2 edition (May 4, 1998) ISBN-10: 0201896850 ISBN-13: 978-0201896855
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *p     = NULL;
        ListNode *lhs   = NULL;
        ListNode *rhs   = NULL;

        if (!head || !head->next)
            return head;

        while (head) {
            p = head;
            head = head->next;

            p->next = lhs;
            lhs = p;

            swap(lhs, rhs);
        }

        lhs = sortList(lhs);
        rhs = sortList(rhs);

        return mergeSortedList(lhs, rhs);
    }

    ListNode* mergeSortedList(ListNode* lhs, ListNode* rhs) {
        ListNode dummy(0);
        ListNode *head = &dummy;

        while (lhs && rhs) {
            if (lhs->val < rhs->val) {
                head->next = lhs;
                lhs = lhs->next;
            }
            else {
                head->next = rhs;
                rhs = rhs->next;
            }

            head = head->next;
        }

        if (lhs) {
            head->next = lhs;
        }

        if (rhs) {
            head->next = rhs;
        }

        return dummy.next;
    }
};