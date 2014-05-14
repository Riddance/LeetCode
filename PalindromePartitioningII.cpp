//this Solution will TLE
class Solution {
public:
    int minCut(string s) {
        int cuts = s.size();

        if (cuts == 0 || cuts == 1) {
            return cuts;
        }

        if (isPalindromeString(s)) {
            return 0;
        }

        vector<int> result = helpFunction(s);

        for (auto p : result) {
            if (p < cuts) {
                cuts = p;
            }
        }

        return cuts;
    }

    vector<int> helpFunction(string s) {
        vector<int> result;

        if (s.size() == 1) {
            result.push_back(0);
            return result;
        }

        for (int i = 1; i <= (int)s.size(); ++i) {
            string subs = s.substr(0, i);
            if (!isPalindromeString(subs)) {
                continue;
            }

            if (i == s.size()) {
                result.push_back(0);
                continue;
            }

            auto t = helpFunction(s.substr(i));
            if (t.empty()) {
                continue;
            }

            for (auto p : t) {
                result.push_back(1 + p);
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

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return 0;
        }

        if (isPalindromeString(s)) {
            return 0;
        }
        
        vector<int> result(len + 1, INT_MAX);
        result[0] = 0;
        result[1] = 0;

        for (int i = 2; i <= len; ++i) {
            string subs = s.substr(0, i);
            if (isPalindromeString(subs)) {
                result[i] = 0;
                continue;
            }

            for (int j = 1; j < i; ++j) {
                subs = s.substr(j, i - j);
                if (isPalindromeString(subs) && result[j] + i < result[i]) {
                    result[i] = result[j] + 1;
                }
            }
        }

        return result[len];
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


//this Solution will AC
class Solution {
public:
    int minCut(string s) {
        int len = s.length();

        if (len == 0 || len == 1) {
            return 0;
        }

        vector<vector<bool> > isPal(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) {
            isPal[i][i] = true;
        }

        vector<int> result(len + 1, INT_MAX);
        result[0] = 0;
        result[1] = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = i; j >= 0; --j) {
                if (s[i] != s[j]) {
                    continue;
                }

                if (i - j > 2 && !isPal[j + 1][i - 1]) {
                    continue;
                }

                isPal[j][i] = true;

                if (j == 0) {
                    result[i + 1] = 0;
                    continue;
                }

                result[i + 1] = min(result[i + 1], result[j] + 1);
            }
        }

        return result[len];
    }
};