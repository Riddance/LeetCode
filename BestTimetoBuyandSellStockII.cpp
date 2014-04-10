class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int result = 0;
    	int p = INT_MAX;

    	auto iter = prices.begin();
    	while (iter != prices.end()) {
    		if (*iter > p) {
    			result += (*iter - p);
    		}

    		p = *iter;
    		++iter;
    	}

    	return result;
    }
};