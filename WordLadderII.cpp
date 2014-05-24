class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;

        if (start == end) {
            return result;
        }

        dict.insert(end);
        dict.erase(start);

        const char *c_start = start.c_str();
        const char *c_end   = (*dict.find(end)).c_str();

        int prev = 0;
        int next = 1;
        vector<unordered_set<const char*> > search_array(2, unordered_set<const char*>());
        unordered_map<const char*, vector<const char*> > result_path_map;
        result_path_map[c_start] = vector<const char *>();

        unordered_set<const char*> find_set;

        search_array[prev].insert(c_start);
        while (!search_array[prev].empty()) {
            search_array[next].clear();

            for (auto val_p : search_array[prev]) {
                find_set.insert(val_p);
            }

            for (auto val_p : search_array[prev]) {

                for (int i = 0; i < (int)strlen(val_p); ++i) {
                    for (char j = 'a'; j <= 'z'; ++j) {
                        if (val_p[i] == j) {
                            continue;
                        }

                        string word(val_p);
                        word[i] = j;

                        auto word_iter = dict.find(word);
                        if (word_iter == dict.end()) {
                            continue;
                        }

                        if (find_set.find((*word_iter).c_str()) != find_set.end()) {
                            continue;
                        }

                        result_path_map[(*word_iter).c_str()].push_back(val_p);
                        search_array[next].insert((*word_iter).c_str());
                    }
                }
            }

            if (!result_path_map[c_end].empty()) {
                search_array[next].clear();
            }

            std::swap(prev, next);
        }

        result.push_back(vector<string>(1, c_end));

        bool find_result_path = true;
        while (find_result_path) {
            vector<vector<string> > str_2d_array = result;
            result.clear();

            for (auto str_array : str_2d_array) {
                auto it = result_path_map.find(dict.find(str_array.front())->c_str());
                if (it != result_path_map.end()) {

                    for (auto w : it->second) {
                        auto k = str_array;
                        k.insert(k.begin(), string(w));
                        result.push_back(k);
                    }

                    if (it->second.size() == 0) {
                        find_result_path = false;
                    }

                    if (it->second.size() == 1 && it->second.front() == c_start) {
                        find_result_path = false;
                    }
                }
            }
        }

        return result;
    }
};
