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
    bool isValidBST(TreeNode *root) {
        vector<TreeNode *> path;
        inorderTravel(root, path);

        TreeNode *prev = NULL;

        for (int i = 0; i < (int)path.size(); ++i) {
            if (prev == NULL) {
                prev = path[i];
                continue;
            }

            if (prev->val >= path[i]->val) return false;

            prev = path[i];
        }

        return true;
    }

    void inorderTravel(TreeNode *root, vector<TreeNode *>& path) {
        if (root == NULL) return;

        inorderTravel(root->left, path);
        path.push_back(root);
        inorderTravel(root->right, path);

        return;
    }
};
