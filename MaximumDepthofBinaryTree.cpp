class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;

        int left_depth = maxDepth(root->left) + 1;
        int right_depth = maxDepth(root->right) + 1;

        return left_depth > right_depth ? left_depth : right_depth;
    }
};
