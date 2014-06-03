/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        RandomListNode *cur_node = head;
        RandomListNode *new_head = NULL;

        while (cur_node)
        {
            RandomListNode *temp = cur_node->next;
            cur_node->next = new RandomListNode(cur_node->label);

            assert(cur_node->next);
            cur_node->next->next = temp;
            cur_node = temp;
        }
        
        cur_node = head;
        while (cur_node && cur_node->next)
        {
            if (cur_node->random)
                cur_node->next->random = cur_node->random->next;

            cur_node = cur_node->next->next;
        }

        if (head)
            new_head = head->next;

        cur_node = head;
        while (cur_node && cur_node->next)
        {
            RandomListNode *temp = cur_node->next;

            cur_node->next = cur_node->next->next;

            if (temp->next)
            {
                temp->next = temp->next->next;
            }

            cur_node = cur_node->next;
        }

        return new_head;
    }
};
