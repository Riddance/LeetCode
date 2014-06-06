class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;

        if (strs.size() == 0) return result;

        int index = 0;

        while (true) {
            if (strs[0].size() <= index) return result;

            char common = strs[0][index];

            for (int i = 0; i < (int)strs.size(); ++i) {
                if (index >= strs[i].size() || common != strs[i][index]) return result;
            }

            ++index;
            result.push_back(common);
        }

        return result;
    }
};
