struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == NULL)
            return true;

        int diff = abs(getTreeDeepth(root->left) - getTreeDeepth(root->right));
        if (diff != 0 && diff != 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);  
    }

    int getTreeDeepth(TreeNode *root) {
        if (root == NULL)
            return 0;

        return max(1 + getTreeDeepth(root->left), 1 + getTreeDeepth(root->right));
    }
};