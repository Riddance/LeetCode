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

            while (j > 0 && d[j] != d[i - 1] && d[j] != '?' && d[i - 1] != '?') {
                j = next_j[j];
            }

            if (d[j] == d[i - 1] || d[j] == '?' || d[i - 1] == '?') {
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

    bool getMatchStr(const char *p, int pos, int &l , int &r) {
        if (p[pos] == '\0') {
            return false;
        }

        while (p[pos] == '*') {
            ++pos;
        }

        l = pos;

        while (p[pos] != '*' && p[pos] != '\0') {
            ++pos;
        }

        r = pos - 1;

        if (l > r) {
            return false;
        }

        if (l == r && p[l] == '\0') {
            return false;
        }

        return true;
    }

    bool isMatch(const char *s, const char *p) {
        int p_cur = 0;
        int s_cur = 0;

        int l = 0;
        int r = 0;

        if (strlen(p) == 0) {
            return strlen(s) == 0;
        }

        if (strlen(s) == 0) {
            return !getMatchStr(p, p_cur, l, r);
        }

        while (getMatchStr(p, p_cur, l, r)) {
            p_cur = r + 1;

            if (l == 0 && r == strlen(p) - 1) {
                if (strlen(s) != strlen(p)) {
                    return false;
                }

                if (kmpStrStr(s, p) == nullptr) {
                    return false;
                }

                return true;
            }

            if (l == 0) {
                if ((int)strlen(s) < r - l + 1) {
                    return false;
                }

                for (int i = 0; i < r - l + 1; ++i) {
                    if (p[i] != s[i] && p[i] != '?') {
                        return false;
                    }
                }

                s_cur = s_cur + r - l + 1;
                continue;
            }

            if (r == strlen(p) - 1) {
                int len_s = (int)strlen(s);
                int len_p = (int)strlen(p);

                if (len_s - s_cur < r - l + 1) {
                    return false;
                }

                for (int i = 0; i < r - l + 1; ++i) {
                    if (s[len_s - i - 1] != p[len_p - i - 1] && p[len_p - i - 1] != '?') {
                        return false;
                    }
                }

                return true;
            }

            string sub_str = string(p + l, r - l + 1);
            const char* find_pos = kmpStrStr(s + s_cur, sub_str.c_str());
            if (find_pos == nullptr) {
                return false;
            }

            s_cur = (int)(find_pos - s + r - l + 1);
        }

        return true;
    }
};
