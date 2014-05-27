class Solution {
public:
    bool getMatchStr(const char *p, int c, int &l, int &r) {
        if (p[c] == '\0') {
            return false;
        }

        while (p[c] == '*') {
            ++c;
        }

        l = c;

        while (p[c] != '*' && p[c] != '\0') {
            ++c;
        }

        r = c;

        if (r - l < 1) {
            return false;
        }

        return true;
    }

    bool isMatch(const char *s, const char *p)
    {
        int l = 0;
        int r = 0;
        int c = 0;

        if (strlen(p) == 0) {
            return strlen(s) == 0;
        }

        while(getMatchStr(p, c, l, r)) {
            
            if (l == 0 && r == strlen(p)) {
                if (strlen(p) != strlen(s)) {
                    return false;
                }

                for (int i = 0; i < (int)strlen(s); ++i) {
                    if (p[i] != s[i] && p[i] != '?') {
                        return false;
                    }
                }

                return true;
            }

            if (l == 0) {
                for (int i = 0; i < (int)r - (int)l; ++i) {
                    if (p[i] != s[i] && p[i] != '?') {
                        return false;
                    }
                }
            }

            if (r == strlen(p)) {
                int len = strlen(s);

                for (int i = 0; i < (int)r - (int)l; ++i) {
                    if (p[r - i - 1] != s[len - i - 1] && p[r - i - 1] != '?') {
                        return false;
                    }
                }

                return true;
            }

            string match_str = string(p + l, r - l);

            bool b_match = false;

            //KMP match string
            int j = 0;
            vector<int> next_j(match_str.size() + 1, 0);
            for (int i = 2; i <= (int)match_str.size(); ++i)
            {
                while (j > 0 && match_str[j] != match_str[i - 1])
                {
                    j = next_j[j];
                }

                if (match_str[j] == match_str[i - 1])
                {
                    j = j + 1;
                }

                next_j[i] = j;
            }

            j = 0;
            for (int i = c; i < (int)strlen(s); ++i)
            {
                while (j > 0 && match_str[j] != s[i] && match_str[j] != '?')
                {
                    j = next_j[j];
                }

                if (match_str[j] == s[i] || match_str[j] == '?')
                {
                    j = j + 1;
                }

                if (j == (int)match_str.size())
                {
                    c = c + j;
                    b_match = true;
                    break;
                }
            }

            if (b_match == false)
            {
                return false;
            }

            c = r;
        }

        return true;
    }
};
