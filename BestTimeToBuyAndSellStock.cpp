class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int l, r;
        l = r = 0;

        if (prices.size() == 0) {
            return 0;
        }

        l = prices[0];

        for (int i = 0; i < (int)prices.size(); ++i) {
            if (prices[i] < l) {
                l = prices[i];
            }

            int c = prices[i] - l;
            if (c > r) {
                r = c;
            }

        }

        return r;
    }
};