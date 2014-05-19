class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;

        if (s.size() == 0 && dict.find("") == dict.end()) {
            return result;
        }

        if ((int)dict.size() == 0) {
            return result;
        }

        unordered_map<string, vector<string> > strToWord;

        helpFunction(s, dict, strToWord);

        return strToWord[s];
    }

    void helpFunction(string s, unordered_set<string> &dict, unordered_map<string, vector<string> > &strToWord) {

        for (int i = 0; i < (int)s.size(); ++i) {

            string word = s.substr(i);

            if (dict.find(word) == dict.end()) {
                continue;
            }

            string subs = s.substr(0, i);
            if (subs.size() == 0) {
                strToWord[s].push_back(s);
                continue;
            }

            if (strToWord.find(subs) == strToWord.end()) {
                helpFunction(subs, dict, strToWord);
            }

            for (auto w : strToWord[subs]) {
                strToWord[s].push_back(w + " " + word);
            }
        }

        return;
    }
};