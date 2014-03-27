struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *p = NULL;
        TreeNode *c = NULL;

        TreeNode *lep = NULL;
        TreeNode *lec = NULL;

        TreeNode *rep = NULL;
        TreeNode *rec = NULL;

        while (root) {
            if (root->left == NULL) {
                p = c;
                c = root;
                root = root->right;
            }
            else {
                TreeNode* t = root->left;
                while (t->right && t->right != root)
                    t = t->right;

                if (t->right == NULL) {
                    t->right = root;
                    root = root->left;
                    continue;
                }
                else {
                    t->right = NULL;
                    p = c;
                    c = root;
                    root = root->right;
                }
            }

            if (p && c && p->val > c->val) {
                if (!lep && !lec) {
                    lep = p;
                    lec = c;
                }
                else {
                    rep = p;
                    rec = c;
                }
            }
        }

        if (lep && rep) {
            std::swap(lep->val, rec->val);
        }
        else if (lep && !rep) {
            std::swap(lep->val, lec->val);
        }

        return;
    }
};