class Solution {
public:
    const char* kmpStrStr(const char* s, const char* d) {
        if (s == nullptr || d == nullptr) {
            return nullptr;
        }

        int len = (int)strlen(d);
        if (len == 0) {
            return s;
        }

        int j = 0;
        vector<int> next_j(len + 1, 0);
        for (int i = 2; i <= len; ++i) {

            while (j > 0 && d[j] != d[i - 1]) {
                j = next_j[j];
            }

            if (d[j] == d[i - 1]) {
                j = j + 1;
            }

            next_j[i] = j;
        }

        j = 0;
        for (int i = 0; i < (int)strlen(s); ++i) {
            while (j > 0 && d[j] != s[i] && d[j] != '?') {
                j = next_j[j];
            }

            if (d[j] == s[i] || d[j] == '?') {
                j = j + 1;
            }

            if (j == len) {
                return s + i - len + 1;
            }
        }

        return nullptr;
    }

    bool isMatch(const char *s, const char *p) {
        return true;
    }
};
