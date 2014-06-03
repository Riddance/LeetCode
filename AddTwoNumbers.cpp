struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head      = NULL;
        ListNode *pre_node  = NULL;
        ListNode *cur_node  = NULL;
        int carry_bit       = 0;

        if (!l1)
            return l2;


        if (!l2)
            return l1;

        ListNode *cur_l1 = l1;
        ListNode *cur_l2 = l2;

        while (cur_l1 && cur_l2)
        {
            cur_node = new ListNode(0);

            if (!head)
                head = cur_node;

            cur_node->val = (cur_l1->val + cur_l2->val + carry_bit) % 10;
            carry_bit = (cur_l1->val + cur_l2->val + carry_bit) / 10;

            if (pre_node)
                pre_node->next = cur_node;

            pre_node = cur_node;

            cur_l1 = cur_l1->next;
            cur_l2 = cur_l2->next;
        }

        while (cur_l1)
        {
            cur_node = new ListNode(0);

            cur_node->val = (cur_l1->val + carry_bit) % 10;
            carry_bit = (cur_l1->val + carry_bit) / 10;

            if (pre_node)
                pre_node->next = cur_node;

            pre_node = cur_node;
            cur_l1 = cur_l1->next;
        }

        while (cur_l2)
        {
            cur_node = new ListNode(0);

            cur_node->val = (cur_l2->val + carry_bit) % 10;
            carry_bit = (cur_l2->val + carry_bit) / 10;

            if (pre_node)
                pre_node->next = cur_node;

            pre_node = cur_node;
            cur_l2 = cur_l2->next;
        }

        if (carry_bit)
        {
            cur_node = new ListNode(0);
            cur_node->val = carry_bit;

            if (pre_node)
                pre_node->next = cur_node;
        }

        return head;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy_node(0);
        int carry_bit = 0;

        ListNode* cur_node = &dummy_node;

        while (l1 || l2) {
            int val1 = 0;
            int val2 = 0;

            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            cur_node->next = new ListNode((val1 + val2 + carry_bit) % 10);
            cur_node = cur_node->next;
            carry_bit = (val1 + val2 + carry_bit) / 10;
        }

        if (carry_bit) {
            cur_node->next = new ListNode(carry_bit);
            cur_node = cur_node->next;
        }

        return dummy_node.next;
    }
};
