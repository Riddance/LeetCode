

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        
    }

    void mergesortList(ListNode *head_pre, ListNode *head, ListNode *tail) {
    	if (head == tail)
    		return;

    	if (head->next == tail) {
    		if (head->val < tail->val)
    			return;
    		else {
    			head_pre->next = tail;
    			head->next = tail->next;
    			tail->next = head;
    			return;
    		}
    	}
    }

    //tail of l1's next node will be l2
    ListNode *mergesortList(ListNode *l1, ListNode *l2, ListNode *end) {
    	if (l1 == l2)
    		return;

    	ListNode *cur_node = NULL;
    	ListNode *ret_node = NULL;
    	ListNode *ins_node = NULL;
    	while (l1 != l2 && l2 != end) {
    		if (l1->val < l2->val) {
    			ins_node = l1;
    			l1 = l1->next;
    		}
    		else {
    			ins_node = l2;
    			l2 = l2->next;
    		}

    		if (ret_node == NULL) {
    			ret_node = ins_node;
    		}
    		else {
    			cur_node->next = ins_node;
    		}

    		cur_node = ins_node;
    	}

    	while (l1 != l2) {
    		if (ret_node == NULL) {
    			ret_node = l1;
    		}
    		else {
    			cur_node->next = l1;
    		}

    		cur_node = l1;

    	}

    	while (l2 != end) {
    		if (ret_node == NULL) {
    			ret_node = l2;
    		}
    		else {
    			cur_node->next = l2;
    		}

    		cur_node = l2;
    	}

    	return ret_node;
    }
};