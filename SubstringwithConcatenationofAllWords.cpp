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


//this Solution will TLE
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> indices;

        std::sort(L.begin(), L.end(), std::less<string>());

        string subs;
        for (auto p : L) {
            subs.append(p);
        }

        int indice = S.find(subs);
        while (indice != string::npos) {
            indices.push_back(indice);

            indice = S.find(subs, indice + 1);
        }

        while (getNextPermutationString(L)) {
            subs.clear();

            for (auto p : L) {
                subs.append(p);
            }

            indice = S.find(subs);
            while (indice != string::npos) {
                indices.push_back(indice);

                indice = S.find(subs, indice + 1);
            }
        }

        return indices;
    }

    bool getNextPermutationString(vector<string>& L) {
        int lhs = (int)L.size() - 2;

        while (lhs >= 0) {
            if (L[lhs] < L[lhs + 1]) {
                break;
            }

            --lhs;
        }

        if (lhs < 0) {
            return false;
        }

        int rhs = lhs + 1;
        assert(rhs < (int)L.size());

        for (int i = rhs; i < (int)L.size(); ++i) {
            if (L[i] > L[lhs] && L[i] < L[rhs]) {
                rhs = i;
            }
        }

        std::swap(L[lhs], L[rhs]);
        std::sort(L.begin() + lhs + 1, L.end(), std::less<string>());

        return true;
    }
};


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (L.size() == 0 || S.size() == 0) {
            return result;
        }

        unordered_map<string, int> LCountMap;
        unordered_map<string, int> FCountMap;

        int len = L[0].length();

        for (auto word : L) {
            ++LCountMap[word];
            assert(word.length() == len);
        }

        for (int i = 0; i <= (int)S.size() - len * (int)L.size(); ++i) {
            string word = S.substr(i, len);
            if (LCountMap.find(word) == LCountMap.end()) {
                continue;
            }

            int c = L.size();
            FCountMap = LCountMap;
            --FCountMap[word];
            --c;

            int j = i + len;

            for (NULL; j <= (int)S.size() - len; j += len) {
                if (c == 0) {
                    break;
                }

                word = S.substr(j, len);

                if (LCountMap.find(word) == LCountMap.end()) {
                    break;
                }

                if (FCountMap[word] == 0) {
                    break;
                }

                --FCountMap[word];
                --c;
            }

            if (j - i == len * (int)L.size()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
