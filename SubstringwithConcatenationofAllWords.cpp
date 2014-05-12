//this Solution will TLE
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        std::vector<int> indices;

        std::set<const char *> wordSet;
        for (int i = 0; i < (int)L.size(); ++i) {
            wordSet.insert(L[i].c_str());
        }

        for (int i = 0; i < (int)S.size(); ++i) {
            if (validIndice(S, i, wordSet)) {
                indices.push_back(i);
            }
        }

        return indices;
    }

    bool validIndice(string& S, int indice, set<const char* > wordSet) {
        if (indice >= (int)S.size()) {
            return false;
        }

        string subS = S.substr(indice);
        const char* str = subS.c_str();
        int len = (int)strlen(str);

        while (!wordSet.empty()) {

            for (auto p : wordSet) {
                int wlen = (int)strlen(p);

                if (len < wlen) {
                    return false;
                }

                if (strncmp(str, p, wlen)) {
                    continue;
                }

                str += wlen;
                wordSet.erase(p);
                break;
            }

            if (len == strlen(str)) {
                return false;
            }

            len = strlen(str);
        }

        return true;
    }
};