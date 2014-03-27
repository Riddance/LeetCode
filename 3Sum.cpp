class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        std::set<std::vector<int> > rs;
        std::vector<std::vector<int> > rv;
        std::vector<int> r(3, 0);

        if (num.size() < 3) {
            return rv;
        }

        std::sort(num.begin(), num.end(), std::less<int>());

        for (int i = 0; i < (int)num.size(); ++i) {
            int lhs = i + 1;
            int rhs = num.size() - 1;

            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            
            while (lhs < rhs) {
                int val = num[lhs] + num[rhs] + num[i];

                if (val == 0) {
                    r[0] = num[i];
                    r[1] = num[lhs];
                    r[2] = num[rhs];
                    rs.insert(r);

                    ++lhs;
                    --rhs;
                }
                else if (val < 0) {
                    ++lhs;
                }
                else {
                    --rhs;
                }
            }
        }

        auto Iter = rs.begin();
        while (Iter != rs.end()) {
            rv.push_back(*Iter);
            ++Iter;
        }

        return rv;
    }
};