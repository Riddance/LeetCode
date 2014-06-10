class Solution {
public:
    int singleNumber(int A[], int n) {
        int bit1 = 0;
        int bit2 = 0;
        int bit3 = 0;

        for (int i = 0; i < n; ++i) {
            bit2 |= (bit1 & A[i]);
            bit1 = bit1 ^ A[i];

            bit3 = ~(bit1 & bit2);
            bit1 = bit3 & bit1;
            bit2 = bit3 & bit2;
        }

        return bit1;
    }
};
