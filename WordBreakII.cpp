class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        if (s.size() == 0 && dict.find("") == dict.end()) {
            return false;
        }

        unordered_map<string, vector<string> > strToWordsMap;

    	return _wordBreak(s, dict, strToWordsMap);
    }

    vector<string> _wordBreak(
    	string s,
    	unordered_set<string> &dict,
    	unordered_map<string, vector<string> > &strToWordsMap
    ) {

    	vector<string> vecStr;

    	if (s.size() == 0) {
    		vecStr.push_back("");
    		return vecStr;
    	}

    	for (int i = 1; i < (int)s.size(); ++i) {
    		string lhsStr = s.substr(0, i);
    		string rhsStr = s.substr(i, s.size() - 1);

    		if (dict.find(lhsStr) == dict.end()) {
    			continue;
    		}

    		if (strToWordsMap.find(rhsStr) == strToWordsMap.end()) {
    			strToWordsMap[rhsStr] = _wordBreak(rhsStr, dict, strToWordsMap);
    		}

    		if ((strToWordsMap[rhsStr]).empty() == false) {
    			vecStr = strToWordsMap[rhsStr];
    			vecStr.push_back(lhsStr);
    			return vecStr;
    		}
    	}

    	return vecStr;
    }
};
