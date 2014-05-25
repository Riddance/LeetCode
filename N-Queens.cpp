class Solution {
public:
    bool isValidPlace(int row, int col, int n, vector<string>& solution) {
        int val = 1;

        for (int i = col - 1; i >= 0; --i) {

            if (solution[row][i] == 'Q') {
                return false;
            }

            if (row - val >= 0 && solution[row - val][i] == 'Q') {
                return false;
            }

            if (row + val < n && solution[row + val][i] == 'Q') {
                return false;
            }

            ++val;
        }

        return true;
    }

    void searchSolution(int col, int n, vector<string>& solution, vector<vector<string> > &result) {
        assert(col <= n);

        if (col == n) {
            result.push_back(solution);
            return;
        }

        for (int row = 0; row < n; ++row) {
            solution[row][col] = 'Q';

            if (isValidPlace(row, col, n, solution)) {
                searchSolution(col + 1, n, solution, result);
            }

            solution[row][col] = '.';
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;

        if (n <= 0 || n == 2 || n == 3) {
            return result;
        }

        vector<string> solution(n, string(n, '.'));

        searchSolution(0, n, solution, result);

        return result;
    }
};