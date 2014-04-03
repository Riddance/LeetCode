class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {

        if (matrix[0].size() != matrix.size()) {
            return;
        }

        if (matrix.size() == 0 || matrix.size() == 1) {
            return;
        }

        int n = (int)matrix.size();

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        int lhs = 0;
        int rhs = n - 1;

        while (lhs < rhs) {
            for (int i = 0; i < n; ++i) {
                std::swap(matrix[i][lhs], matrix[i][rhs]);
            }
            
            ++lhs;
            --rhs;
        }
        
        return;
    }
};
