
// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	TreeLinkNode *prev = NULL;
    	TreeLinkNode *curr = NULL;

    	int seq_curr = 1;
    	int seq_next = 1;

    	while (seq_curr <= seq_next) {
    		curr = GetNextNode(root, seq_curr);

            if (curr && (curr->left || curr->right)) {
                seq_next = seq_curr * 2 + 1;
            }

            if (prev)
                prev->next = curr;

            if (curr)
                prev = curr;

            if (seq_curr == 1 || (seq_curr & (seq_curr - 1) == 0)) {
                prev = NULL;
            }

            seq_curr++;
    	}

        return;
    }

    TreeLinkNode* GetNextNode(TreeLinkNode* root, int seq_req) {
    	int seq_init = 1;

    	while (seq_init < seq_req) {
    		if (IsInLeft(seq_init, seq_req)) {
    			root = root->left;
    			seq_init = seq_init * 2;
    		}
    		else {
    			root = root->right;
    			seq_init = seq_init * 2 + 1;
    		}

    		if (!root)
    			break;
    	}

    	return root;
    }

//whether require sequence(node) is in current sequence(node)'s left subtree. 
    bool IsInLeft(int seq_cur, int seq_req) {
    	assert(seq_cur <= seq_req);

    	while (seq_req > seq_cur * 2 + 1)
    		seq_req = seq_req / 2;

    	return seq_req % 2? true : false;
    }
};

//Populating Next Right Points in Each Node 1
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* lhs = NULL;
        TreeLinkNode* rhs = NULL;

        if (!root)
            goto out;

        lhs = root->left;
        rhs = root->right;

        while (lhs && rhs) {
            lhs->next = rhs;

            lhs = lhs->right;
            rhs = rhs->left;
        }

        connect(root->left);
        connect(root->right);

        out:
        return;
    }
};

//Populating Next Right Points in Each Node 2
class Solution {
public:
    void connect(TreeLinkNode *root) {

    }
};