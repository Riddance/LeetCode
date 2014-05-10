class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    	vector<vector<int> > result;

    	std::sort(candidates.begin(), candidates.end());

    	if (target == 0) {
    		result.push_back(vector<int>());
    		return result;
    	}

    	if (candidates.size() == 0 ) {
    		return result;
    	}

    	int val = candidates.back();
    	vector<int> t = candidates;
    	t.resize(t.size() - 1);

    	assert(val);
    	for (int i = 0; i <= target / val; ++i) {
    		auto seques = combinationSum(t, target - i * val);

    		for (int j = 0; j < seques.size(); ++j) {
    			seques[j].insert(seques[j].end(), i, val);
    		}

    		result.insert(result.end(), seques.begin(), seques.end());
    	}

    	return result;
    }
};
