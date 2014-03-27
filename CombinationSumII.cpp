class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        std::sort(num.begin(), num.end(), std::less<int>);
        int i = 0;
        int sum = 0;
        while (sum <= target) {
            sum = sum + num[i];
            ++i;
        }
        
    }
};