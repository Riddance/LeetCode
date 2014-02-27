struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
    	if (!root)
    		return 0;

    	int max_path_sum = 0;

    	std::stack<TreeNode*> node_stack;
    	node_stack.push(root);

    	while (node_stack.empty() == false) {
    		TreeNode* node = node_stack.top();
    		node_stack.pop();

    		max_path_sum = max(max_path_sum, node->val + getMaxPathFromRootToLeaf(node->left) + getMaxPathFromRootToLeaf(node->right));
    		
    		if (node->left)
    			node_stack.push(node->left);

    		if (node->right)
    			node_stack.push(node->right);
    	}
    }

    int getMaxPathFromRootToLeaf(TreeNode *root) {
    	if (!root)
    		return 0;

    	return root->val + max(getMaxPathFromRootToLeaf(root->left), getMaxPathFromRootToLeaf(root->right));
    }
};
