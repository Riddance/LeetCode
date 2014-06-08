class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int result = 0;
        set<int> int_set;
        if (num.size() == 0) return result;
        for (int i = 0; i < (int)num.size(); ++i) int_set.insert(num[i]);

        int prev = 0;
        int len = 0;
        auto it = int_set.begin();
        prev = *it;
        ++it;
        len = 1;
        while (it != int_set.end()) {
            if (*it != prev + 1) {
                result = max(result, len);
                len = 1;
                prev = *it;
                ++it;
                continue;
            }

            ++len;
            prev = *it;
            ++it;
        }

        result = max(result, len);

        return result;
    }
};
