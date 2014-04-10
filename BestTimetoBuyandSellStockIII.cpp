class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int p = 0;
    	int len = prices.size();

    	if (len < 2) {
    		return p;
    	}

    	vector<int> forwardProfits(len, 0);
    	vector<int> backwardProfits(len, 0);

    	int valley = prices[0];
    	int peek   = prices[len - 1];

    	for (int i = 0; i < len; ++i) {
    		valley = min(prices[i], valley);
    		if (i > 0) {
    			forwardProfits[i] = max(forwardProfits[i - 1], prices[i] - valley);
    		}
    	}

    	for (int i = len - 1; i >= 0; --i) {
    		peek = max(prices[i], peek);
    		if (i < len - 1) {
    			backwardProfits[i] = max(backwardProfits[i + 1], peek - prices[i]);
    		}
    		if (i == 0) {
    			p = max(p, backwardProfits[0]);
    		}
    		else if (i == len - 1) {
    			p = max(p, forwardProfits[len - 1]);
    		}
    		else {
    			p = max(p, backwardProfits[i + 1] + forwardProfits[i]);
    		}
    	}

    	return p;
    }
};
