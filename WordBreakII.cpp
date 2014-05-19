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

        for (auto w : dict) {
            strToWord[w] = vector<string>();
        }

        helpFunction(s, strToWord);

        return strToWord[s];
    }

    void helpFunction(string s, unordered_map<string, vector<string> > &strToWord) {
        for (int i = 1; i <= (int)s.size(); ++i) {
            string word = s.substr(0, i);

            if (strToWord.find(word) == strToWord.end() || !strToWord[word].empty()) {
                continue;
            }

            string subs = s.substr(i);
            if (subs.size() == 0) {
                continue;
            }

            if (strToWord.find(subs) == strToWord.end()) {
                helpFunction(subs, strToWord);
            }

            if (strToWord.find(subs) == strToWord.end()) {
                continue;
            }

            if (strToWord[subs].empty()) {
                strToWord[s].push_back(word + " " + subs);
            }

            for (auto w : strToWord[subs]) {
                strToWord[s].push_back(word + " " + w);
            }
        }

        return;
    }
};
