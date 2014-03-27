class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0)
            return 0;

        int max_area = 0;

        std::vector<int> tmp(matrix[0].size(), 0);
        std::vector<std::vector<int> > widths(matrix.size(), tmp);

        for (int i = 0; i < (int)matrix.size(); ++i) {
            widths[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }

        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j) {
                if (j == 0) {
                    continue;
                }

                widths[i][j] = matrix[i][j] == '1' ? (widths[i][j - 1] + 1) : 0;
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int height = i;
                int width_min = widths[i][j];

                while (height >= 0) {
                    width_min = min(width_min, widths[height][j]);
                    max_area = max(max_area, width_min * (i - height + 1));
                    --height;
                }
        }

        return max_area;
    }
};