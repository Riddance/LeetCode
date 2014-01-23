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



class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
	    struct cmp {
	        bool operator() (const int& lhs, const int& rhs) const {
	            return lhs < rhs;
	        }
	    };

	    std::set<int, cmp> nums;
	    while (head) {
	        nums.insert(head->val);
	        head = head->next;
	    }

	    TreeNode* nodes = (TreeNode*)malloc(nums.size() * sizeof(TreeNode));
	    if (nodes) {
	        TreeNode* cur = nodes;
	        std::set<int, cmp>::iterator it = nums.begin();
	        while (it != nums.end()) {
	            (cur++)->val = *(it++);
	        }
	    }

	    return makeTree(nodes, 0, nums.size());
    }

    TreeNode *makeTree(TreeNode* nodes, int lhs, int rhs) {
    	if (lhs > rhs) {
    		return NULL;
    	}

    	int r = (lhs + rhs) / 2;
    	TreeNode * root = nodes[r];
    	root->left = makeTree(nodes, lhs, r - 1);
    	root->right = makeTree(nodes, r + 1, rhs);

    	return root;
    }
};