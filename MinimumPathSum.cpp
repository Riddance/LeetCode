class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum, r, c;
        sum = r = c = 0;

        r = (int)grid.size();
        if (r) {
            c = (int)grid[0].size();
        }

        std::vector<std::vector<int> > v;
        std::vector<int> t(c, 0);

        if (!r || !c) {
            goto out;
        }

        v.resize(r, t);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!i && !j) {
                    v[i][j] = grid[i][j];
                    continue;
                }

                if (i == 0) {
                    v[0][j] = v[0][j - 1] + grid[0][j];
                    continue;
                }

                if (j == 0) {
                    v[i][0] = v[i - 1][0] + grid[i][0];
                    continue;
                }

                v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
            }
        }

        sum = v[r - 1][c - 1];
        out:
        return sum;
    }
};