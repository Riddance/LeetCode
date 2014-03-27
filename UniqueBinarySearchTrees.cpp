class Solution {
public:
    int numTrees(int n) {
        int r = 0;

        if (n == 0)
            return 1;

        if (n == 1)
            return 1;

        for (int i = 1; i <= n; ++i) {
            r = r + numTrees(i - 1)*numTrees(n - i);
        }
        
        return r;
    }
};