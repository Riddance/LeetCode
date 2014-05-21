//will TLE
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 0;
        }

        dict.insert(start);
        dict.insert(end);

        typedef unordered_set<string>::iterator STRING_SET_IT;
        struct STRING_IT_COMPARE {
            bool operator() (STRING_SET_IT lhs, STRING_SET_IT rhs) const {
                return *lhs < *rhs;
            }
        };

        struct IT_SET {
            set<STRING_SET_IT, STRING_IT_COMPARE> Element;
        };

        struct ADJACENT_MAP{
            unordered_map<string, IT_SET> Element;
        }adjacent_map;

        for (auto i = dict.begin(); i != dict.end(); ++i) {
            auto j = i;
            ++j;

            for (NULL; j != dict.end(); ++j) {
                if (getDiff(*i, *j) == 1) {
                    adjacent_map.Element[*i].Element.insert(j);
                }
            }
        }

        queue<string> search_queue;
        search_queue.push(start);
        search_queue.push("");

        IT_SET path_set;

        path_set.Element.insert(dict.find(start));

        int step = 2;
        while (!search_queue.empty()) {
            string word = search_queue.front();
            search_queue.pop();

            if (word == "" && !search_queue.empty()) {
                ++step;
                search_queue.push("");
                continue;
            }

            for (auto w : adjacent_map.Element[word].Element) {
                if (path_set.Element.find(w) != path_set.Element.end()) {
                    continue;
                }

                if (*w == end) {
                    return step;
                }

                path_set.Element.insert(w);
                search_queue.push(*w);
            }
        }

        return 0;
    }

    int getDiff(const string &L, const string &R) {
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

class Solution {
public:
};
