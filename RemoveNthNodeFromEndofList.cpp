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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;

        ListNode *lhs = head;
        ListNode *rhs = head;

        ListNode *prev = NULL;

        while(--n && rhs) rhs = rhs->next;
        if (n) return head;

        while (rhs->next) {
            rhs = rhs->next;
            prev = lhs;
            lhs = lhs->next;
        }

        if (prev) prev->next = lhs->next;
        else head = lhs->next;
        
        return head;
    }
};
