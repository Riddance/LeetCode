
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

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return makeTree(preorder, inorder, Range(0, preorder.size() - 1), Range(0, inorder.size() - 1));
  }

  TreeNode *makeTree(std::vector<int> &pre, std::vector<int> &in, Range raPre, Range raIn) {
    if (raPre.lhs > raPre.rhs || raIn.lhs > raIn.rhs)
      return NULL;

    if (raPre.lhs < 0 || raPre.rhs >= pre.size() || raIn.lhs < 0 || raIn.rhs >= in.size())
      return NULL;

    TreeNode *node = new TreeNode(pre[raPre.lhs]);
    if (node) {
      int i = raIn.lhs;
      while (i <= raIn.rhs) {
        if (in[i] == pre[raPre.lhs]) {
          break;
        }
        ++i;
      }
      assert(i <= raIn.rhs);
      int ls = i - raIn.lhs;
      int rs = raIn.rhs - i;

      if (ls) {
        node->left = makeTree(pre, in, Range(raPre.lhs + 1, raPre.lhs + ls), Range(raIn.lhs, i - 1));
      }

      if (rs) {
        node->right = makeTree(pre, in, Range(raPre.rhs - rs + 1, raPre.rhs), Range(i + 1, raIn.rhs));
      }
    }

    return node;
  }
};