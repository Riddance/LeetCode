struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode* nodes = (TreeNode *)malloc(sizeof(TreeNode) * num.size());
        if (nodes == NULL)
            return NULL;

        TreeNode* cur = nodes;
        std::vector<int>::iterator it = num.begin();
        while (it != num.end()) {
            (cur++)->val = *it++;
        }

        return makeTree(nodes, 0, num.size() - 1);
    }

    TreeNode* makeTree(TreeNode* nodes, int lhs, int rhs) {
        if (lhs > rhs)
            return NULL;

        int r = (lhs + rhs) / 2;
        TreeNode* root = &nodes[r];
        root->left = makeTree(nodes, lhs, r - 1);
        root->right = makeTree(nodes, r + 1, rhs);

        return root;
    }
};