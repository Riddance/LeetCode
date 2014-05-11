class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	return helpFunction(1, n, k);
    }

    vector<vector<int> > helpFunction(int lhs, int rhs, int k) {
    	vector<vector<int> > result;
    	if (k == 0 || lhs > rhs) {
    		goto out;
    	}

    	if (k == 1) {
    		for (int i = lhs; i <= rhs; ++i) {
    			result.push_back(vector<int>(1, i));
    		}
    		goto out;
    	}

    	for (int i = lhs; i <= rhs; ++i) {
    		auto combinations = helpFunction(i + 1, rhs, k - 1);

    		for (int j = 0; j < combinations.size(); ++j) {
    			combinations[j].insert(combinations[j].begin(), i);
    		}

    		result.insert(result.begin(), combinations.begin(), combinations.end());
    	}

    	out:
    	return result;
    }
};
