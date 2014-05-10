class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    //  std::sort(num.begin(), num.end());
    //  vector<vector<int> > result;
    //  result = helpFunction(num, target);

    //  set<vector<int> > uniqueset;
    //  auto it = result.begin();
    //  while (it != result.end()) {
    //      if (uniqueset.find(*it) == uniqueset.end()) {
    //          uniqueset.insert(*it);
    //          continue;
    //      }

    //      it = result.erase(it);
    //  }

    //  return result;

        std::map<int, int> nummap;
        for (int i = 0; i < num.size(); ++i) {
            if (nummap.find(num[i]) == nummap.end()) {
                nummap[num[i]] = 1;
                continue;
            }

            ++nummap[num[i]];
        }

        return helpFunction(nummap, target);
    }

    vector<vector<int> > helpFunction(map<int, int>& nummap, int target) {
        vector<vector<int> > result;

        if (target == 0) {
            result.push_back(vector<int>());
            return result;
        }

        if (nummap.empty()) {
            return result;
        }

        map<int, int> t = nummap;
        std::pair<int, int> kv = *(t.rbegin());
        auto It = t.rbegin();
        t.erase((++It).base());

        int high = (target / kv.first) < kv.second ? (target / kv.first) : kv.second;
        for(int i = 0; i <= high; ++i) {
            auto sq = helpFunction(t, target - i * kv.first);
            if (i == 0) {
                result.insert(result.end(), sq.begin(), sq.end());
                continue;
            }

            for (int j = 0; j < sq.size(); ++j) {
                sq[j].insert(sq[j].end(), i, kv.first);
            }

            result.insert(result.end(), sq.begin(), sq.end());
        }

        return result;
    }

    // vector<vector<int> > helpFunction(vector<int> &num, int target) {
    //  vector<vector<int> > result;

    //  if (target == 0) {
    //      result.push_back(vector<int>());
    //      return result;
    //  }

    //  if (num.size() == 0) {
    //      return result;
    //  }

    //  int val = num.back();
    //  vector<int> t = num;
    //  t.resize(t.size() - 1);

    //  int high = target >= val ? 1 : 0;
    //  for (int i = 0; i <= high; ++i) {
    //      auto sq = helpFunction(t, target - i * val);
    //      if (i == 0) {
    //          result.insert(result.end(), sq.begin(), sq.end());
    //          continue;
    //      }

    //      for(int j = 0; j < sq.size(); ++j) {
    //          sq[j].push_back(val);
    //      }

    //      result.insert(result.end(), sq.begin(), sq.end());
    //  }

    //  return result;
    // }
};