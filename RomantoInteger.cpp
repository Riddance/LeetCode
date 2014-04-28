class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        const char* thousandStr[] = {
            "MMM",
            "MM",
            "M"
        };

        const char* hundredStr[] = {
            "CM",
            "DCCC",
            "DCC",
            "DC",
            "D",
            "CD",
            "CCC",
            "CC",
            "C"
        };

        const char* tenStr[] = {
            "XC",
            "LXXX",
            "LXX",
            "LX",
            "L",
            "XL",
            "XXX",
            "XX",
            "X"
        };

        const char* digitStr[] = {
            "IX",
            "VIII",
            "VII",
            "VI",
            "V",
            "IV",
            "III",
            "II",
            "I"
        };

        const char* pos = s.c_str();

        for (int i = 0; i < sizeof(thousandStr) / sizeof(const char *); ++i) {
            int len = (int)strlen(thousandStr[i]);

            if (strncmp(pos, thousandStr[i], len) == 0) {
                result += 1000 * (sizeof(thousandStr) / sizeof(const char *) - i);
                pos += len;
                break;
            }
        }

        for (int i = 0; i < sizeof(hundredStr) / sizeof(const char *); ++i) {
            int len = (int)strlen(hundredStr[i]);

            if (strncmp(pos, hundredStr[i], len) == 0) {
                result += 100 * (sizeof(hundredStr) / sizeof(const char *) - i);
                pos += len;
                break;
            }
        }

        for (int i = 0; i < sizeof(tenStr) / sizeof(const char *); ++i) {
            int len = (int)strlen(tenStr[i]);

            if (strncmp(pos, tenStr[i], len) == 0) {
                result += 10 * (sizeof(tenStr) / sizeof(const char *) - i);
                pos += len;
                break;
            }
        }

        for (int i = 0; i < sizeof(digitStr) / sizeof(const char *); ++i) {
            int len = (int)strlen(digitStr[i]);

            if (strncmp(pos, digitStr[i], len) == 0) {
                result += 1 * (sizeof(digitStr) / sizeof(const char *) - i);
                pos += len;
                break;
            }
        }

        return result;
    }
};
