struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getOneSideMaxPathSum(TreeNode *root, int &path_sum) {
        if (root == NULL) {
            return -1;
        }

        int left_side = getOneSideMaxPathSum(root->left, path_sum);
        int right_side = getOneSideMaxPathSum(root->right, path_sum);
        int val = root->val;
        path_sum = max(path_sum, val);
        path_sum = max(path_sum, val + left_side);
        path_sum = max(path_sum, val + right_side);
        path_sum = max(path_sum, val + left_side + right_side);

        return max(max(val + left_side, val + right_side), max(val, 0));
    }

    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int result = root->val;
        getOneSideMaxPathSum(root, result);

        return result;
    }
};
