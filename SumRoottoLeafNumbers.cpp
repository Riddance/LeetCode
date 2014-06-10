class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        return dfs_add(root, 0);
    }

    int dfs_add(TreeNode * cur_node, int sum) {
        if (!cur_node) return 0;

        sum = sum * 10 + cur_node->val;
        
        if (!cur_node->left && !cur_node->right) return sum;

        return dfs_add(cur_node->left, sum) + dfs_add(cur_node->right, sum);
    }
};
