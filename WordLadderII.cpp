class Solution {
public:
<<<<<<< HEAD
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
    }
=======
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > result;

    dict.insert(end);
    dict.erase(start);

    const char *c_start = start.c_str();
    const char *c_end   = (*dict.find(end)).c_str();

    int prev = 0;
    int next = 1;
    vector<unordered_set<const char*> > search_array(2, unordered_set<const char*>());
    unordered_map<const char*, vector<const char*> > result_path_map;

    search_array[prev].insert(c_start);
    while (!search_array[prev].empty()) {
        search_array[next].clear();

        for (auto val_p : search_array[prev]) {
            for (int i = 0; i < (int)strlen(val_p); ++i) {
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (val_p[i] == j) {
                        continue;
                    }

                    string word = val_p;
                    word[i] = j;

                    auto word_iter = dict.find(word);
                    if (word_iter == dict.end()) {
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

    prev = 0;
    next = 1;
    search_array[prev].clear();
    search_array[next].clear();
    search_array[prev].insert(c_end);

    result.push_back(vector<string>(1, c_end));

    while (!search_array[prev].empty()) {
        search_array[next].clear();

        for (auto r : search_array[prev]) {
            auto It = result_path_map.find(r);
            while (It != result_path_map.end()) {

            }
        }

        std::swap(prev, next);
    }

    return result;
}
>>>>>>> FETCH_HEAD
};
