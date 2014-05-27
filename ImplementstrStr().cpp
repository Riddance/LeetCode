class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == nullptr || needle == nullptr) {
            return nullptr;
        }

        if (strlen(needle) == 0) {
            return haystack;
        } 

        int len = (int)strlen(needle);
        int j = 0;
        vector<int> next_j(len + 1, 0);
        for (int i = 2; i <= len; ++i) {

            while (j > 0 && needle[j] != needle[i - 1]) {
                j = next_j[j];
            }

            if (needle[j] == needle[i - 1]) {
                j = j + 1;
            }

            next_j[i] = j;
        }

        j = 0;
        for (int i = 0; i < (int)strlen(haystack); ++i) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next_j[j];
            }

            if (needle[j] == haystack[i]) {
                j = j + 1;
            }

            if (j == len) {
                return haystack + i - len + 1;
            }
        }

        return nullptr;
    }
};