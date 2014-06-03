class Solution {
public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeNode *cur_node;
        stack<TreeNode*> walk_stack;

        if (root)
            walk_stack.push(root);
        else
            return;

        while (!walk_stack.empty()) {
            cur_node = walk_stack.top();
            walk_stack.pop();

            if (cur_node->right) {
                walk_stack.push(cur_node->right);
            }

            if (cur_node->left) {
                walk_stack.push(cur_node->left);
            }
            
            cur_node->left = NULL;

            if (!walk_stack.empty())
                cur_node->right = walk_stack.top();
            else
                cur_node->right = NULL;
        }
        
        return;
    }
};
