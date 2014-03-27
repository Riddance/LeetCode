class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;

        std::vector<int> p;
        std::vector<int> c;
        p.push_back(0);

        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    c.push_back(p[j] + triangle[i][j]);
                }
                else if (j == triangle[i].size() - 1) {
                    c.push_back(p[j - 1] + triangle[i][j]);
                }
                else {
                    c.push_back(min(p[j], p[j - 1]) + triangle[i][j]);
                }
            }

            p = c;
            c.clear();
        }

        return *std::min_element(p.begin(), p.end());
    }
};