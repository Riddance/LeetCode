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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > paths;
        vector<TreeNode *> path_nodes;
        stack<TreeNode *> travel_stack;

        if (root == NULL) return paths;

        travel_stack.push(root);
        while (!travel_stack.empty()) {
            TreeNode *node = travel_stack.top();
            sum = sum - node->val;

            path_nodes.push_back(node);
            travel_stack.pop();

            if (node->left) travel_stack.push(node->left);
            if (node->right) travel_stack.push(node->right);

            //find one path
            if (!node->left && !node->right && !sum) {
                vector<int> path;
                for (auto p : path_nodes) path.push_back(p->val);
                paths.push_back(path);
            }

            //roll back
            while (!path_nodes.empty()) {
                if (travel_stack.empty()) break;

                if (
                    (path_nodes.back())->left == travel_stack.top() || 
                    (path_nodes.back())->right == travel_stack.top()
                    )break;
                else {
                    sum = sum + (path_nodes.back())->val;
                    path_nodes.pop_back();
                }
            }
        }

        return paths;
    }
};

