class Solution {
public:
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s == NULL) {
            return false;
        }

        int lhs = 0;
        int rhs = strlen(s) - 1;

        //trim string
        while (lhs <= rhs) {
            if (s[lhs] == ' ') {
                ++lhs;
                continue;
            }

            if (s[rhs] == ' ') {
                --rhs;
                continue;
            }

            break;
        }

        //empty string
        if (lhs > rhs) {
            return false;
        }

        bool bDot = false;
        bool bSig = false;
        bool bNum = false;
        //now we get first number
        int i = lhs;
        for (NULL ; i <= rhs; ++i) {
            if (i == lhs && (s[i] == '+' || s[i] == '-')) {
                bSig = true;
                continue;
            }

            if (s[i] == '.' && !bDot) {
                bDot = true;
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                bNum = true;
                continue;
            }

            break;
        }
        lhs = i;
        if ((bSig || bDot) && !bNum) {
            return false;
        }

        if (lhs > rhs) {
            return true;
        }

        //not end with e, we return false
        if (s[lhs] != 'E' && s[lhs] != 'e') {
            return false;
        }

        if (!bNum) {
            return false;
        }

        //now we get second number
        ++lhs;
        i = lhs;
        bSig = false;
        bDot = false;
        bNum = false;
        for (NULL; i <= rhs; ++i) {
            if (i == lhs && (s[i] == '+' || s[i] == '-')) {
                bSig = true;
                continue;
            }

            if (s[i] == '.' && !bDot) {
                bDot = true;
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                bNum = true;
                continue;
            }

            break;
        }
        lhs = i;
        if (!bNum) {
            return false;
        }

        if (bDot && !bSig) {
            return false;
        }

        if (lhs <= rhs) {
            return false;
        }

        return true;
    }
};