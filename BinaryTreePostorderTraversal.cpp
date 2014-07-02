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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;

        walk_function(root, result);

        return result;
    }

    void walk_function(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
            return;

        walk_function(root->left, result);
        walk_function(root->right, result);
        result.push_back(root->val);

        return;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        std::stack<TreeNode *> walk_stack;
        TreeNode * last_visite = NULL;

        while (!walk_stack.empty() || root) {
            if (root) {
                walk_stack.push(root);
                root = root->left;
                continue;
            }

            if (!walk_stack.empty()) {
                if (walk_stack.top()->right == last_visite || walk_stack.top()->right == NULL) {
                    last_visite = walk_stack.top();
                    result.push_back(last_visite->val);
                    walk_stack.pop();
                }
                else {
                    root = walk_stack.top()->right;
                }
            }
        }

        return result;
    }

};

