class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;

        int cur = 0;
        int lhs = 0;
        int rhs = 0;

        while (s[lhs] == ' ') {
            ++lhs;
        }

        rhs = lhs;
        cur = lhs;

        while (s[cur] != '\0') {
            //assert(rhs - 1 >= lhs)
            if (s[cur] != ' ' || (s[cur] == ' ' && s[rhs - 1] != ' ')) {
                s[rhs++] = s[cur];
            }

            ++cur;
        }
        
        if (s[rhs - 1] == ' ') {
            rhs = rhs - 1;
        }

        string tmp(s, lhs, rhs - lhs);
        s = tmp;
        
        if (s.size() == 0) {
            return;
        }

        cur = 0;
        lhs = 0;
        rhs = 0;

        //first, reverse every word in the string
        while (s[cur] != '\0') {
            if (s[cur] == ' ') {
                rhs = cur - 1;
                while (lhs < rhs) {
                    char tmp = s[lhs];
                    s[lhs] = s[rhs];
                    s[rhs] = tmp;
                    ++lhs;
                    --rhs;
                }
                lhs = cur + 1;
                rhs = lhs;
            }
            ++cur;
        }
        
        --cur;
        
        //reverse the end word
        while (lhs < cur) {
            char tmp = s[lhs];
            s[lhs] = s[cur];
            s[cur] = tmp;
            ++lhs;
            --cur;
        }

        //now reverse the whole string
        lhs = 0;
        rhs = (int)s.size() - 1;
        while (lhs < rhs) {
            char tmp = s[lhs];
            s[lhs] = s[rhs];
            s[rhs] = tmp;
            ++lhs;
            --rhs;
        }

        return;
    }
};