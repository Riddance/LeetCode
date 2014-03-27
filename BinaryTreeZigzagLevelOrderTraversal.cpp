struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
            q.push(NULL);
        }

        std::vector<std::vector<int> > r;
        std::vector<int> v;
        bool l = true;

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (node == NULL) {
                if (!l) {
                    std::reverse(v.begin(), v.end());
                }
                
                r.push_back(v);
                v.clear();
                l = !l;

                if (!q.empty())
                    q.push(NULL);
                
                continue;
            }

            v.push_back(node->val);
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        return r;
    }
};