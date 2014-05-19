class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
	    vector<string> result;

	    if ((int)s.size() > 12) {
	        return result;
	    }

	    for (int i = 0; i < (int)s.length(); ++i) {
	        if (s[i] < '0' || s[i] > '9') {
	            return result;
	        }
	    }

	    result = helpfunction(s, 4);

	    return result;     
    }

	bool isValidSection(const string &s) {
		if (s.length() == 0 || s.length() > 3) {
	        return false;
	    }

	    if ((int)s.size() > 1 && s[0] == '0') {
	    	return false;
	    }

	    int num = 0;
	    for (int i = 0; i < (int)s.length(); ++i) {

	        num = num * 10 + (int)(s[i] - '0');
	    }

	    if (num < 0 || num > 255) {
	        return false;
	    }

	    return true;
	}

	vector<string> helpfunction(const string s, int c) {
	    vector<string> result;

	    assert(c >= 1 && c <= 4);

	    if ((int)s.size() == 0 || (int)s.size() < c) {
	        return result;
	    }

	    if (c == 1) {
	        if (isValidSection(s)) {
	            result.push_back(s);
	        }

	        return result;
	    }

	    int len = (s.length() < 3) ? s.length() : 3;

	    for (int i = 1; i <= len; ++i) {
	        string subs = s.substr(0, i);

	        if (!isValidSection(subs)) {
	            continue;
	        }

	        vector<string> t = helpfunction(s.substr(i), c - 1);
	        if (t.empty()) {
	            continue;
	        }

	        for (auto p : t) {
	            result.push_back(subs + "." + p);
	        }
	    }

	    return result;
	}
};
