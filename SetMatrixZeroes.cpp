class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if (matrix.size() == 0 || matrix[0].size() == 0) {
    		return;
    	}

    	std::vector<bool> bRow(matrix.size(), false);
    	std::vector<bool> bColum(matrix[0].size(), false);

    	for (int r = 0; r < (int)matrix.size(); ++r) {
    		for (int c = 0; c < (int)matrix[0].size(); ++c) {
    			if (matrix[r][c] == 0) {
    				bRow[r] = true;
    				bColum[c] = true;
    			}
    		}
    	}

    	for (int r = 0; r < (int)matrix.size(); ++r) {
    		for (int c = 0; c < (int)matrix[0].size(); ++c) {
    			if (bRow[r]) {
    				matrix[r][c] = 0;
    			}

    			if (bColum[c]) {
    				matrix[r][c] = 0;
    			}
    		}
    	}

    	return;
    }
};
