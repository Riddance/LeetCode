class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s == NULL) return 0;

        int rhs = (int)strlen(s) - 1;
        while (rhs >= 0 && s[rhs] == ' ') --rhs;
        int lhs = rhs;
        while (lhs >= 0 && s[lhs] != ' ') --lhs;

        return rhs - lhs;
    }
};
