class Solution {
public:
        string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.  
        if (nRows <= 1 || s.size() <= 1)  
            return s;

        string result;
        int nCols = (s.size() / (nRows + nRows - 2) + 1) * nRows;

        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                int nSquence = -1;

                if (j % (nRows - 1) == 0) {
                    nSquence = j / (nRows - 1) * (nRows + nRows - 2) + i;
                }
                else if ( (i + j % (nRows - 1)) == nRows - 1) {
                    nSquence = j / (nRows - 1) * (nRows + nRows - 2) + nRows - 1 + j % (nRows - 1);
                }

                if (nSquence != -1 && nSquence < (int)s.size()) {
                    result.push_back(s[nSquence]);
                }
            }
        }
        
        return result;
    }
};