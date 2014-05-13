class Solution {
public:
    int minCut(string s) {
    	int cuts = s.size();

    	if (cuts == 0 || cuts == 1) {
    		return cuts;
    	}

    	vector<int> result = helpFunction(s);

    	for (auto p : result) {
    		if (p < cuts) {
    			cuts = p;
    		}
    	}

    	return cuts;
    }

    vector<int> helpFunction(string s) {
    	vector<int> result;

    	if (s.size() == 1) {
    		result.push_back(0);
    		return result;
    	}

    	for (int i = 1; i <= (int)s.size(); ++i) {
    		string subs = s.substr(0, i);
    		if (!isPalindromeString(s)) {
    			continue;
    		}

    		if (i == s.size()) {
    			result.push_back(0);
    			continue;
    		}

    		auto t = helpFunction(s.substr(i));
    		if (t.empty()) {
    			continue;
    		}

    		for (auto p : t) {
    			result.push_back(1 + p);
    		}

    	}

    	return result;
    }

    bool isPalindromeString(string s) {
	    if (s.size() == 0) {
	        return true;
	    }

	    int lhs = 0;
	    int rhs = (int)s.size() - 1;

	    while (lhs < rhs) {
	        if (s[lhs] != s[rhs]) {
	            return false;
	        }

	        ++lhs;
	        --rhs;
	    }

	    return true;
	}
};