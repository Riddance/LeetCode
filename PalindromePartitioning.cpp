
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if (s.size() == 0) {
            return result;
        }

        if (s.size() == 1) {
            result.push_back(vector<string>(1, s));
            return result;
        }

        for (int i = 1; i <= (int)s.size(); ++i) {
            string subs = s.substr(0, i);
            if (!isPalindromeString(subs)) {
                continue;
            }

            if (i == s.size()) {
                result.push_back(vector<string>(1, s));
                continue;
            }

            auto t = partition(s.substr(i));
            if (t.empty()) {
                continue;
            }

            for (auto p : t) {
                p.insert(p.begin(), subs);
                result.push_back(p);
            }

        }

        return result;
    }

    bool isPalindromeString(string s) {
        if (s.size() == 0) {
            return true;
        }

        int lhs = 0;
        int rhs = (int)s.size() - 1;
        while (lhs < rhs) {
            if (s[lhs] != s[rhs]) {
                return false;
            }

            ++lhs;
            --rhs;
        }

        return true;
    }
};