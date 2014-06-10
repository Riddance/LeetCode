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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;

        if (!root->left && !root->right) return 1;
        else if (root->left && root->right) {
            int left_depth = minDepth(root->left) + 1;
            int right_depth = minDepth(root->right) + 1;

            return left_depth < right_depth ? left_depth : right_depth;
        }
        else if (root->left) return minDepth(root->left) + 1;
        else return minDepth(root->right) + 1;
            
    }
};