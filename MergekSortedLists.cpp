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
    static bool isNull(const ListNode* node) {
        return node == NULL;
    }

    static bool cmpNodes(const ListNode *lhs, const ListNode *rhs) {
        assert(lhs);
        assert(rhs);

        return lhs->val > rhs->val;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode dummy_node(0);
        ListNode* cur = &dummy_node;

        vector<ListNode*>::iterator it_lhs = lists.begin();
        vector<ListNode*>::iterator it_rhs = lists.end();
        it_rhs = std::remove_if(it_lhs, it_rhs, isNull);
        lists.resize(std::distance(it_lhs, it_rhs));

        std::make_heap(lists.begin(), lists.end(), cmpNodes);

        while (lists.begin() != lists.end()) {
            cur->next = lists.front();
            cur = cur->next;

            std::pop_heap(lists.begin(), lists.end(), cmpNodes);
            lists.pop_back();

            if (cur->next) {
                lists.push_back(cur->next);
                std::push_heap(lists.begin(), lists.end(), cmpNodes);
            }
        }
        assert(cur->next == NULL);

        return dummy_node.next;
    }
};
