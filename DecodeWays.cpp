class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }

        unordered_map<string, int> decodeMap;
        return helpFunction(s, decodeMap);
    }

    int helpFunction(string s, unordered_map<string, int>& decodeMap) {
        int ways = 0;

        if (s.size() == 0) {
            ways = 1;
            goto out;
        }

        if (s[0] < '1' || s[0] > '9') {
            goto out;
        }

        if (s.size() == 1) {
            ways = 1;
            goto out;
        }

        if (decodeMap.find(s) != decodeMap.end()) {
            ways = decodeMap[s];
            goto out;
        }

        ways = helpFunction(string(s.begin() + 1, s.end()), decodeMap);

        if ((s[0] == '1' && s[1] >= '0' && s[1] <= '9') || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')) {
            ways += helpFunction(string(s.begin() + 2, s.end()), decodeMap);
        }

        decodeMap[s] = ways;

        out:
        return ways;
    }
};
