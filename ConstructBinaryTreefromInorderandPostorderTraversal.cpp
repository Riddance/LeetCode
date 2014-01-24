
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	struct Range {
		int lhs;
		int rhs;
		Range(int x = 0, int y = 0) : lhs(x), rhs(y) {}
	};
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	return makeTree(inorder, postorder, Range(0, inorder.size() - 1), Range(0, postorder.size() - 1));
    }

    TreeNode *makeTree(std::vector<int> &in, std::vector<int> &post, Range raIn, Range raPost) {
    	if (raIn.lhs > raIn.rhs || raIn.lhs < 0 || raIn.rhs >= in.size())
    		return NULL;

    	if (raPost.lhs > raPost.rhs || raPost.lhs < 0 || raPost.rhs >= post.size())
    		return NULL;

    	TreeNode *node = new TreeNode(post[raPost.rhs]);
    	if (node) {
    		int i = raIn.lhs;
    		while (i <= raIn.rhs) {
    			if (in[i] == post[raPost.rhs]) {
    				break;
    			}
    			++i;
    		}
    		assert(i <= raIn.rhs);
    		int ls = i - raIn.lhs;
    		int rs = raIn.rhs - i;
    		if (ls) {
    			node->left = makeTree(in, post, Range(raIn.lhs, i - 1), Range(raPost.lhs, raPost.lhs + ls - 1));
    		}

    		if (rs) {
    			node->right = makeTree(in, post, Range(i + 1, raIn.rhs), Range(raPost.rhs - rs, raPost.rhs - 1));
    		}
    	}

    	return node;
    }
};