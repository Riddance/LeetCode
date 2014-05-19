class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (getDiff(start, end) == 1) {
            return 2;
        }

        if (start == end) {
            return 0;
        }

        if (!dict.size()) {
            return 0;
        }

        unordered_set<string> sets;
        unordered_set<string> sete;
        for (auto w : dict) {

            bool bs = (getDiff(w, start) == 1);
            bool be = (getDiff(w, end) == 1);

            if (bs && be) {
                return 3;
            }

            if (bs) {
                sets.insert(w);
            }

            if (be) {
                sete.insert(w);
            }
        }

        int result = 0;

        for (auto i : sets) {
            for (auto j : sete) {

                dict.erase(i);
                dict.erase(j);

                int len = ladderLength(i, j, dict);

                dict.insert(i);
                dict.insert(j);

                if (len == 0) {
                    continue;
                }

                if (result == 0) {
                    result = len + 1;
                }

                if (len + 1 < result) {
                    result = len + 1;
                }
            }
        }
        
        return result;
    }

    int getDiff(string &L, string &R) {
        int diff = 0;

        assert(L.size() == R.size());
        for (int i = 0; i < (int)L.size(); ++i) {
            if (L[i] != R[i]) {
                ++diff;
            }
        }

        return diff;
    }
};
