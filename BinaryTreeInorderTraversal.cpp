struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        
        inorder_traver(root, result);
        
        return result;
    }

public:
    void inorder_traver(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        
        inorder_traver(root->left, result);
            
        result.push_back(root->val);
        
        inorder_traver(root->right, result);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        std::stack<TreeNode *> walk_stack;

        while (!walk_stack.empty() || root) {
            if (root) {
                walk_stack.push(root);
                root = root->left;
                continue;
            }

            if (!walk_stack.empty()) {
                root = walk_stack.top();
                walk_stack.pop();
                result.push_back(root->val);
                root = root->right;
                continue;
            }
        }

        return result;
    }
};
