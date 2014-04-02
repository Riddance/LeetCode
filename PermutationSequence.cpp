class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string strNum;

        if (n <= 0 || k <= 0) {
            return strNum;
        }

        std::vector<int> factorials(n, 1);
        std::vector<bool> isUsed(n, false);
        
        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * (i + 1);
        }

        while (k > factorials[n - 1]) {
            k = k % factorials[n - 1];
        }

        if (k > 0) {
            --k;
        }

        for (int i = n - 1; i >= 0; --i) {
            int quotient = 0;

            if (i == 0) {
                quotient = 0;
            }
            else {
                quotient = k / factorials[i - 1];
                k = k % factorials[i - 1];
            }

            for (int j = 0; j < n; ++j) {
                if (isUsed[j] == false) {
                    --quotient;
                }

                if (quotient < 0) {
                    isUsed[j] = true;
                    strNum.push_back('0' + j + 1);
                    break;
                }
            }
        }

        return strNum;
    }
};

//this will TLE
class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        std::string numStr;

        for (int i = 1; i <= n; ++i) {
            numStr.push_back('0' + i);
        }

        if (n < 2) {
            return numStr;
        }

        for (int i = 0; i < k - 1; ++i) {
            if (!getNextPermutationString(numStr)) {
                break;
            }
        }

        return numStr;
    }

    bool getNextPermutationString(std::string &Str) {
        int swapSrc = (int)Str.size() - 2;

        while (swapSrc >= 0) {
            if (Str[swapSrc] < Str[swapSrc + 1]) {
                break;
            }
            --swapSrc;
        }
        
        if (swapSrc < 0) {
            return false;
        }

        int swapDst = swapSrc + 1;
        assert(swapDst < Str.size());

        for (int i = swapSrc + 1; i < (int)Str.size(); ++i) {
            if (Str[i] > Str[swapSrc] && Str[i] < Str[swapDst]) {
                swapDst = i;
            }
        }

        std::swap(Str[swapSrc], Str[swapDst]);
        std::sort(Str.begin() + swapSrc + 1, Str.end(), std::less<char>());

        return true;
    }
};
