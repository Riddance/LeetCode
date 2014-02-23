class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
    	if (matrix.size() == 0)
    		return 0;

    	std::vector<int> tmp(matrix[0].size(), 0);
    	std::vector<std::vector<int> > result(matrix.size(), tmp);
    	result[0][0] = matrix[0][0] == '1' ? 1 : 0;
    	int m = result[0][0];

    	for (int i = 0; i < matrix.size(); ++i) {
    		for (int j = 0; j < matrix[0].size(); ++j) {
    			if (i == 0 && j == 0) {
    				continue;
    			}

    			if (i == 0) {
    				result[i][j] = matrix[i][j] == '1' ? result[i][j - 1] + 1 : 0;
    				m = max(m, result[i][j]);
    				continue;
    			}

    			if (j == 0) {
    				result[i][j] = matrix[i][j] == '1' ? result[i - 1][j] + 1 : 0;
    				m = max(m, result[i][j]);
    				continue;
    			}

    			if (matrix[i][j] == '0') {
    				continue;
    			}

    			if (matrix[i - 1][j] == '0' && matrix[i][j - 1] == '0') {
    				result[i][j] = 1;
    				m = max(m, result[i][j]);
    				continue;
    			}

    			if (matrix[i - 1][j] == '0') {
    				result[i][j] = result[i][j - 1] + 1 - result[i - 1][j - 1];
    				m = max(m, result[i][j]);
    				continue;
    			}

    			if (matrix[i][j - 1] == '0') {
    				result[i][j] = result[i - 1][j] + 1 - result[i - 1][j - 1];
    				m = max(m, result[i][j]);
    				continue;
    			}

    			if (matrix[i - 1][j - 1] == '0') {
    				result[i][j] = max(result[i - 1][j], result[i][j - 1]) + 1;
    				m = max(m, result[i][j]);
    				continue;
    			}

    			result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + 1;
    			m = max(m, result[i][j]);
    		}
    	}

    	return m;
    }
};