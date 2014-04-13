//Levenshtein distance
//http://en.wikipedia.org/wiki/Levenshtein_distance


//Recursive will TLE
class Solution {
public:
    int minDistance(string word1, string word2) {
        return LevenshteinDistance(word1, word1.size(), word2, word2.size());
    }

    int LevenshteinDistance(string s, int len_s, string t, int len_t) {
        if (len_s == 0) {
            return len_t;
        }

        if (len_t == 0) {
            return len_s;
        }

        int cost = 0;

        if (s[len_s - 1] != t[len_t - 1]) {
            cost = 1;
        }

        /* return minimum of delete char from s, delete char from t, and delete char from both */
        return min(
            min(LevenshteinDistance(s, len_s - 1, t, len_t), LevenshteinDistance(s, len_s, t, len_t - 1)) + 1, 
            LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost
        );
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }

        int lhs = (int)word1.size();
        int rhs = (int)word2.size();

        if (lhs == 0) {
            return rhs;
        }

        if (rhs == 0) {
            return lhs;
        }

        vector<vector<int> >distances(lhs + 1, vector<int>(rhs + 1, 0));

        for (int i = 1; i <= lhs; ++i) {
            distances[i][0] = i;
        }

        for (int i = 1; i <= rhs; ++i) {
            distances[0][i] = i;
        }

        for (int i = 1; i <= lhs; ++i) {
            for (int j = 1; j <= rhs; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    distances[i][j] = distances[i - 1][j - 1];
                    continue;
                }

                distances[i][j] = min(min(distances[i - 1][j] + 1, distances[i][j - 1] + 1), distances[i - 1][j - 1] + 1);
            }
        }

        return distances[lhs][rhs];
    }
};
