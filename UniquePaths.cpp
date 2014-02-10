class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
        	return 0;

        std::vector<std::vector<int> > r;
        std::vector<int> t(n, 0);
        r.resize(m, t);

        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (i == 0 || j == 0) {
        			r[i][j] = 1;
        			continue;
        		}

        		r[i][j] = r[i - 1][j] + r[i][j - 1];
        	}
        }
        
        return r[m - 1][n - 1];
    }
};