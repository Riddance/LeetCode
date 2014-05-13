class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        return helpFunction(matrix, pair<int, int>(0, 0), pair<int, int>(row - 1, col - 1), target);
    }

    bool helpFunction(vector<vector<int> > &matrix, pair<int, int> low, pair<int, int> high, int target) {

        if (target < matrix[low.first][low.second]) {
            return false;
        }

        if (target > matrix[high.first][high.second]) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int lsq = low.first * col + low.second;
        int hsq = high.first * col + high.second;
        int msq = (lsq + hsq) / 2;

        if (lsq > hsq) {
            return false;
        }

        pair<int, int> mid;
        mid.first = msq / col;
        mid.second = msq % col;

        if (matrix[mid.first][mid.second] == target) {
            return true;
        }

        if (low == high) {
            return false;
        }

        if (matrix[mid.first][mid.second] > target) {
            return helpFunction(matrix, low, pair<int, int>((msq - 1) / col, (msq - 1) % col), target);
        }

        return helpFunction(matrix, pair<int, int>((msq + 1) / col, (msq + 1) % col), high, target);
    }
};
