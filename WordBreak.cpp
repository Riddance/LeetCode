class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {

        if (s.size() == 0) {
                return true;
        }

        for (int i = s.size(); i > 0; --i) {
            if (dict.find(s.substr(0, i)) != dict.end()) {
                if (wordBreak(s.substr(i, s.size() - i), dict)) {
                    return true;
                }
            }
        }

        return false;
    }
};
