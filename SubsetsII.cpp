class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	
    	vector<vector<int> > result(1, vector<int>());

    	if (S.size() == 0) {
    		return result;
    	}

    	std::sort(S.begin(), S.end(), std::less<int>());

    	int l = 0;
    	int r = 0;
    	int p = 0;

    	for (int i = 0; i < (int)S.size(); ++i) {

    		r = result.size();

    		if (i > 0 && S[i] == S[i - 1]) {
    			l = p;
    		}
    		else {
    			l = 0;
    		}

    		for (int j = r - 1; j >= l; --j) {
    			result.push_back(result[j]);
    			(result.back()).push_back(S[i]);
    		}

    		p = r;
    	}

    	return result;
    }
};
