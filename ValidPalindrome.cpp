class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int lhs = 0;
        int rhs = (int)s.size() - 1;

        while (lhs < rhs)
        {
            char val1 = s[lhs];
            char val2 = s[rhs];

            if (!isalpha(val1) && !isdigit(val1)) {
                ++lhs;
                continue;
            }

            if (!isalpha(val2) && !isdigit(val2)) {
                --rhs;
                continue;
            }

            if (isalpha(val1)) val1 = tolower(val1);

            if (isalpha(val2)) val2 = tolower(val2);

            if (val1 == val2) {
                ++lhs;
                --rhs;
            }
            else return false;
        }

        return true;
    }
};
