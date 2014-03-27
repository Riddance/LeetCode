class Solution {
public:
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        //trim string
        while (*s == ' ') {
            ++s;
        }

        int len = (int)strlen(s);
        while (len && *(s + len - 1) == ' ') {
            --len;
        }

        if (!len) {
            return false;
        }

        bool s = false;
        bool d = false;

        for (int i = 0; i < len; ++i) {
            char c = *(s + i);
            if (isdigit(c)) {
                d = true;
            }
            else if (c == '.' || c == 'e') {
                if (s == true) {
                    return false;
                }
                s = true;
            }
            else if (c == '+' || c == '-') {
                if (i != 0 || len == 1) {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        if (!d)
            return false;

        return true;
    }
};