class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int flag = 1;
        if (digits.size() == 0)
            goto out;

        for (int i = digits.size() - 1; i >= 0; --i) {
            int q = (digits[i] + flag) / 10;
            int m = (digits[i] + flag) % 10;
            digits[i] = m;
            flag = q;
        }

        if (flag) {
            digits.insert(digits.begin(), flag);
        }

        out:
        return digits;
    }
};