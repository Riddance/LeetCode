class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {

        int row = board.size();
        if (row != 9) {
            return;
        }

        int col = board[0].size();
        if (col != 9) {
            return;
        }

        vector<vector<int> > vecNum(row, vector<int>(col, 0x3FE));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int val = (int)(board[i][j] - '0');

                for (int k = 0; k < row; ++k) {
                    vecNum[k][j] &= ~(1 << val);
                }

                for (int k = 0; k < col; ++k) {
                    vecNum[i][k] &= ~(1 << val);
                }

                int celRow = i / 3;
                int celCol = j / 3;

                for (int m = celRow; m < celRow + 3; ++m) {
                    for (int n = celCol; n < celCol + 3; ++n) {
                        vecNum[m][n] &= ~(1 << val);
                    }
                }

                vecNum[i][j] = 1 << val;
            }
        }

        multimap

    }
};
