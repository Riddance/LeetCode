class Solution {
public:
    bool isValidPlace(int col, int n, vector<int>& solution) {

        for (int i = 0; i <= col - 1; ++i) {

            if (solution[i] == solution[col]) {
                return false;
            }

            if (abs(i - col) == abs(solution[i] - solution[col])) {
                return false;
            }
        }

        return true;
    }

    void getSolutions(int col, int n, int &total, vector<int>& solution) {
        assert(col <= n);

        if (col == n) {
            ++total;
            return;
        }

        for (int row = 0; row < n; ++row) {
            solution[col] = row;

            if (isValidPlace(col, n, solution)) {
                getSolutions(col + 1, n, total, solution);
            }

            solution[col] = -1;
        }

        return;
    }

    int totalNQueens(int n) {
        int total = 0;

        vector<int> solution(n, -1);

        getSolutions(0, n, total, solution);

        return total;
    }
};
