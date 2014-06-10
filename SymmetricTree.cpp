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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<TreeNode *> lhs_order;
        stack<TreeNode *> rhs_order;

        TreeNode * lhs_node;
        TreeNode * rhs_node;

        if (!root) return true;

        if (!root->left && !root->right) return true;
        else if (root->left && root->right) {
            lhs_order.push(root->left);
            rhs_order.push(root->right);
        }
        else return false;
        
        while (!lhs_order.empty() && !rhs_order.empty()) {
            lhs_node = lhs_order.top();
            rhs_node = rhs_order.top();
            
            lhs_order.pop();
            rhs_order.pop();

            if (lhs_node->val != rhs_node->val) return false;
            if (lhs_node->left && !rhs_node->right) return false;
            if (!lhs_node->left && rhs_node->right) return false;
            if (lhs_node->right && !rhs_node->left) return false;
            if (!lhs_node->right && rhs_node->left) return false;

            if (lhs_node->left) lhs_order.push(lhs_node->left);
            if (lhs_node->right) lhs_order.push(lhs_node->right);
            if (rhs_node->right) rhs_order.push(rhs_node->right);
            if (rhs_node->left) rhs_order.push(rhs_node->left);
        }
        
        return true;
    }
};