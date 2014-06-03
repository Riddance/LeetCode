/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;

        stack<TreeNode *> walk_stack;

        if (root)
            walk_stack.push(root);
        
        while (!walk_stack.empty()) {
            TreeNode *cur_node = walk_stack.top();
            walk_stack.pop();
            
            assert(cur_node);
            result.push_back(cur_node->val);

            if (cur_node->right)
                walk_stack.push(cur_node->right);

            if (cur_node->left)
                walk_stack.push(cur_node->left);
        }
        
        return result;
    }
};
