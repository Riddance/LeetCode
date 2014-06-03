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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode *> walk_queue;
        vector<vector<int> > results;
        vector<int> result;

        if (!root)
            return results;
        else
            walk_queue.push(root);

        walk_queue.push(NULL);

        while (!walk_queue.empty()) {
            TreeNode *temp = walk_queue.front();
            walk_queue.pop();

            if (!temp && !result.empty()) {
                results.push_back(result);
                result.clear();
                continue;
            }
            
            result.push_back(temp->val);
            
            if (temp->left)
                walk_queue.push(temp->left);
                
            if (temp->right)
                walk_queue.push(temp->right);
                
            if (walk_queue.size() > 1 && !(walk_queue.front()))
                walk_queue.push(NULL);
        }

        return results;
    }
};
