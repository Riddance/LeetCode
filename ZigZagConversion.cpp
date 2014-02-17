class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.  
        if (nRows <= 1 || s.size() <= 1)  
        	return s;

        string result;
        int nCols = s / (nRows + nRows - 2);

        for (int i = 0; i < nRows; ++i) {
        	for (int j = 0; i < nCols; ++j) {
        		if (j % (nRows - 1) == 0) {
        			int nSquence = j / (nRows - 1) * (nRows + nRows - 2) + i;
        			if (nSquence < s.size()) {
        				result.push_back(s[nSquence]);
        			}
        			continue;
        		}

        		if ((j / (nRows - 1) % 2 == 0 && i == j % (nRows - 1)) ||
        		(j / (nRows - 1) % 2 != 0 && (i + j % (nRows - 1)) == nRows - 1)) {
        			int nSquence = j / (nRows - 1) * (nRows + nRows - 2) + nRows - 1 + j % (nRows - 1) - 1;
        			if (nSquence < s.size()) {
        				result.push_back(s[nSquence]);
        			}
        			continue;
        		}
        	}
        }

        return result;      
    }
};