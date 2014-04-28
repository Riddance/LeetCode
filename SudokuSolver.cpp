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

        vector<vector<int> > vecNum(row, vector<int>(col, 0));
        
    }
};
