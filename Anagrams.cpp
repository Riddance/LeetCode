class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        std::unordered_map<std::string, std::vector<string> > result_map;
        std::vector<std::string> result;

        for (int i = 0; i < (int)strs.size(); ++i) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            (result_map[str]).push_back(strs[i]);
        }
        
        for (auto it = result_map.begin(); it != result_map.end(); ++it) {
            if ((it->second).size() > 1) {
                result.insert(result.begin(), (it->second).begin(), (it->second).end());
            }
        }

        return result;
    }
};