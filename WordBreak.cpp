//will TLE
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {

        if ((int)s.size() == 0) {
                return true;
        }

        for (int i = (int)s.size(); i > 0; --i) {
            if (dict.find(s.substr(0, i)) != dict.end()) {
                if (wordBreak(s.substr(i, s.size() - i), dict)) {
                    return true;
                }
            }
        }

        return false;
    }
};

//use a unorderd_map to recorder result
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0 && dict.find("") == dict.end()) {
            return false;
        }

        std::unordered_map<std::string, bool> strToBoolMap;
        return _wordBreak(s, dict, strToBoolMap);
    }


    bool _wordBreak(
        std::string s,
        std::unordered_set<std::string> &dict,
        std::unordered_map<std::string, bool> &strToBoolMap
    ) {
        if (s.size() == 0) {
            return true;
        }

        for (int i = 1; i <= (int)s.size(); ++i) {
            if (dict.find(s.substr(0, i)) == dict.end()) {
                continue;
            }

            assert(s.size() >= i);
            std::string suffixStr = s.substr(i, s.size() - i);

            if (strToBoolMap.find(suffixStr) == strToBoolMap.end()) {
                strToBoolMap[suffixStr] = _wordBreak(suffixStr, dict, strToBoolMap);
            }

            if (strToBoolMap[suffixStr]) {
                return true;
            }
        }
        
        return false;
    }
};

