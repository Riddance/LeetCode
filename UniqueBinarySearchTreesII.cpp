
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return makeTrees(1, n);
    }

    std::vector<TreeNode *> makeTrees(int lhs, int rhs) {
        std::vector<TreeNode *> v;

        if (lhs == rhs) {
            TreeNode* t = new TreeNode(lhs);
            v.push_back(t);
        }
        else if (lhs < rhs) {
            for (int k = lhs; k <= rhs; ++k) {
                std::vector<TreeNode *> l = makeTrees(lhs, k - 1);
                std::vector<TreeNode *> r = makeTrees(k + 1, rhs);
                for (int i = 0; i < l.size(); ++i) {
                    for (int j = 0; j < r.size(); ++j) {
                        TreeNode* t = new TreeNode(k);
                        t->left = l[i];
                        t->right = r[j];
                        v.push_back(t);
                    }
                }
            }
        }
        else {
            v.push_back(NULL);
        }

        return v;
    }
};