class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row = (int)board.size();

        if (row != 9) {
            return false;
        }

        int col = (int)board[0].size();
        if (col != 9) {
            return false;
        }

        std::vector<int> validRow(9, 0);
        std::vector<int> validCol(9, 0);
        std::vector<int> validCel(9, 0);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int val = (int)(board[i][j] - '0');

                if (val > 9 || val < 1) {
                    return false;
                }

                if (validRow[i] & (1 << val)) {
                    return false;
                } 
                validRow[i] = validRow[i] | (1 << val);

                if (validCol[j] & (1 << val)) {
                    return false;
                }
                validCol[j] = validCol[j] | (1 << val);

                int cel = (i / 3) * 3 + (j / 3);
                if (validCel[cel] & (1 << val)) {
                    return false;
                }
                validCel[cel] = validCel[cel] | (1 << val);
            }
        }

        return true;
    }
};