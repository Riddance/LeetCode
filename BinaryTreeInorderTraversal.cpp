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