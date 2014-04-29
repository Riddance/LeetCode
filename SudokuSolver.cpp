class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        dfsSolveSudoku(board);
        return;
    }

    bool dfsSolveSudoku(vector<vector<char> > &board) {
        int row = board.size();

        if (row != 9) {
            return false;
        }

        int col = board[0].size();
        if (col != 9) {
            return false;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {

                    for (int k = 1; k <= 9; ++k) {
                        board[i][j] = '0' + k;

                        if (checkValid(board, i, j)) {
                            if (dfsSolveSudoku(board)) {
                                return true;
                            }
                        }
                        
                        board[i][j] = '.';
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool checkValid(vector<vector<char> > &board, int x, int y) {

        for (int i = 0; i < board.size(); ++i) {
            if (i != x && board[i][y] == board[x][y]) {
                return false;
            }
        }

        for (int i = 0; i < board[0].size(); ++i) {
            if (i != y && board[x][i] == board[x][y]) {
                return false;
            }
        }

        int celRow = (x / 3) * 3;
        int celCol = (y / 3) * 3;

        for (int i = celRow; i < celRow + 3; ++i) {
            for (int j = celCol; j < celCol + 3; ++j) {
                if (i == x && j == y) {
                    continue;
                }

                if (board[i][j] == board[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }
};
