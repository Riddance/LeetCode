class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;

        r.push_back(0);
        if (n == 0) {
            return r;
        }

        for (int i = 0; i < n; ++i) {
            int val = 1 << i;

            int usize = r.size();
            for (int j = usize - 1; j >= 0; --j) {
                r.push_back(val + r[j]);
            }
        }

        return r;
    }
};
