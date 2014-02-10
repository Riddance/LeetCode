class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int r, c;
    	if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
    		return 0;
    	}

    	r = obstacleGrid.size();
    	c = obstacleGrid[0].size();

    	std::vector<std::vector<int> > v;
    	std::vector<int> t(c, 0);
    	v.resize(r, t);

    	for (int i = 0; i < r; ++i) {
    		for (int j = 0; j < c; ++j) {
    			if (i == 0 && j == 0) {
    				v[i][j] = 1;
    				continue;
    			}

    			if (i == 0) {
    				v[i][j] = obstacleGrid[i][j - 1] ? 0 : v[i][j - 1];
    				continue;
    			}

    			if (j == 0) {
    				v[i][j] = obstacleGrid[i - 1][j] ? 0 : v[i - 1][j];
    				continue;
    			}

    			int u = obstacleGrid[i - 1][j] ? 0 : v[i - 1][j];
    			int l = obstacleGrid[i][j - 1] ? 0 : v[i][j - 1];
    			v[i][j] = l + u;
    		}
    	}

    	if (obstacleGrid[r - 1][c - 1]) {
    		return 0;
    	}
    	else {
    		return v[r - 1][c - 1];
    	}
    }
};