struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root){
        if (root == NULL)
            return;

        TreeLinkNode *cur = root->next;
        TreeLinkNode *p = NULL;
        while (cur) {
            if (cur->left) {
                p = cur->left;
                break;
            }

            if (cur->right) {
                p = cur->right;
                break;
            }

            cur = cur->next;
        }

        if (root->right) {
            root->right->next = p;
        }

        if (root->left) {
            root->left->next = root->right? root->right : p;
        }

        connect(root->right);
        connect(root->left);
    }
};