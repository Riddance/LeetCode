class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int r, c, k;

        std::vector<int> v;
        r = c = k = 0;
        r = matrix.size();
        if (r) {
            c = matrix[0].size();
        }

        if (!r || !c)
            goto out;

        while (k < (max(r, c) / 2 + max(r, c) % 2)) {
            int up, down, left, right;

            up = down = left = right = 0;

            up = k;
            down = r - k - 1;

            left = k;
            right = c - k - 1;
            
            //output up row
            if (up >= 0 && up <= r - 1 && up <= down) {
                for (int i = k; i <= right; ++i) {
                    v.push_back(matrix[up][i]);
                }
            }

            if (up == down && left == right && up == left) {
                break;
            }

            //output right column
            if (right >= 0 && right <= c - 1 && left <= right) {
                for (int i = k + 1; i <= down - 1; ++i) {
                    v.push_back(matrix[i][right]);
                }
            }

            //output down row
            if (down >= 0 && down <= r - 1 && up < down) {
                for (int i = right; i >= k; --i) {
                    v.push_back(matrix[down][i]);
                }
            }

            //output left column
            if (left >= 0 && left <= c - 1 && left < right) {
                for (int i = down - 1; i >= k + 1; --i) {
                    v.push_back(matrix[i][left]);
                }
            }

            ++k;
        }

        out:
        return v;
    }
};