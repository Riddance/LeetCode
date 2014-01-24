
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	if (preorder.empty())
    		return NULL;

    	TreeNode *cur = new TreeNode;
    	if (cur) {
    		std::vector<int> lhs_preorder;
    		std::vector<int> lhs_inorder;
    		std::vector<int> rhs_preorder;
    		std::vector<int> rhs_inorder;

    		cur->val = *preorder.begin();

    		cur->left = buildTree(lhs_preorder, lhs_inorder);
    		cur->right = buildTree(rhs_preorder, rhs_inorder);
    	}

        return cur;
    }
};