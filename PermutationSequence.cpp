class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string strNum;

        std::vector<int> factorials(n, 0);
        factorials[1] = 1;
        for (int i = 2; i < n; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }

        std::vector<bool> isUsed(n, false);
        
        --k;

        for (int i = n - 1; i > 0; --i) {

            int interNum = k / factorials[i];
            k = k % factorials[i];

            for (int j = 0; j < n; ++j) {
                if (isUsed[j] == false) {
                    --interNum;
                }

                if (interNum < 0) {
                    isUsed[j] = true;
                    strNum.push_back('0' + j + 1);
                    break;
                }
            }
        }

        return strNum;
    }
};
