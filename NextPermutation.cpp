class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int num_count = num.size();

        if (num_count < 2) return;

        int i = 0;

        for (i = num_count - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) break;
        }

        if ( i == -1) {
            sort(num.begin(), num.end());
            return;
        }

        int swap_pos = i + 1;

        for (int j = i + 1; j < num_count; ++j) {
            if (num[j] > num[i] && num[j] < num[swap_pos]) swap_pos = j;
        }

        std::swap(num[i], num[swap_pos]);
        sort((num.begin() + i + 1), num.end());

        return;
    }
};
