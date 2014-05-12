class Solution {
public:
    string minWindow(string S, string T) {
        char strT[255];
        char strC[255];

        memset(strT, 0, sizeof(strT));
        memset(strC, 0, sizeof(strC));

        for (auto c : T) {
            ++strT[c];
            ++strC[c];
        }

        int lenS = S.length();
        int lenT = T.length();

        int lhs = 0;
        int rhs = 0;

        string result;

        for (NULL; rhs < lenS; ++rhs) {
            if (strT[S[rhs]] > 0) {
                --strC[S[rhs]];

                if (strC[S[rhs]] >= 0) {
                    --lenT;
                }
            }

            if (lenT == 0) {
                while (lhs <= rhs) {
                    if (strT[S[lhs]] == 0) {
                        ++lhs;
                        continue;
                    }

                    if (strC[S[lhs]] < 0) {
                        ++strC[S[lhs]];
                        ++lhs;
                        continue;
                    }
                    else {
                        break;
                    }
                }

                if (rhs - lhs + 1 < result.length() || result.length() == 0) {
                    result = S.substr(lhs, rhs - lhs + 1);
                }
            }
        }

        return result;
    }
};