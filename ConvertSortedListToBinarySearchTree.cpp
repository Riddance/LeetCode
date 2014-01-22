struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//brute force method
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	TreeNode *root = NULL;

    	while (head) {
    		root = insertNewNode(root, head->val);
    		head = head->next;
    	}

    	return root;
    }

    TreeNode* insertNewNode(TreeNode* node, int val) {
    	if (node == NULL) {
    		node = new TreeNode(val);
    		goto out;
    	}

    	if (val < node->val) {
    		node->left = insertNewNode(node->left, val);
    		if (abs(getTreeHeight(node->left) - getTreeHeight(node->right)) == 2) {
    			if (val < node->left->val) {
    				node = rotateRight(node);
    			}
    			else {
    				node = rotateLeftRight(node);
    			}
    		}
    	}
    	else if (val > node->val) {
    		node->right = insertNewNode(node->right, val);
    		if (abs(getTreeHeight(node->left) - getTreeHeight(node->right)) == 2) {
    			if (val > node->right->val) {
    				node = rotateLeft(node);
    			}
    			else {
    				node = rotateRightLeft(node);
    			}
    		}
    	}

    	out:
    	return node;
    }

    TreeNode* rotateLeft(TreeNode* node) {
    	TreeNode* rt = node->right;
    	node->right = rt->left;
    	rt->left = node;

    	return rt;
    }

    TreeNode* rotateRight(TreeNode* node) {
    	TreeNode* lf = node->left;
    	node->left = lf->right;
    	lf->right = node;

    	return lf;
    }

    TreeNode* rotateLeftRight(TreeNode* node) {
    	node->left = rotateLeft(node->left);

    	return rotateRight(node);
    }

    TreeNode* rotateRightLeft(TreeNode* node) {
    	node->right = rotateRight(node->right);

    	return rotateLeft(node);
    }

    int getTreeHeight(TreeNode* root) {
    	if (root == NULL)
    		return 0;

    	return max(1 + getTreeHeight(root->left), 1 + getTreeHeight(root->right));
    }
};