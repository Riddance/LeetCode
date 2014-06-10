class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;

        unordered_multimap<int, int> val_map_index;
        for (int i = 0; i < (int)numbers.size(); ++i) {
            val_map_index.insert(make_pair(numbers[i], i + 1));
        }

        std::sort(numbers.begin(), numbers.end());
        int lhs = 0;
        int rhs = numbers.size() - 1;

        int val1 = 0;
        int val2 = 0;
        while (lhs < rhs) {
            if (numbers[lhs] + numbers[rhs] == target) {
                val1 = numbers[lhs];
                val2 = numbers[rhs];
                break;
            }

            if (numbers[lhs] + numbers[rhs] < target) ++lhs;

            if (numbers[lhs] + numbers[rhs] > target) --rhs;
        }

        if (val1 == val2) {
            auto range = val_map_index.equal_range(val1);
            for_each(
                range.first,
                range.second,
                [&result](unordered_multimap<int,int>::value_type &x){result.push_back(x.second);}
            );
        }
        else {
            result.push_back(val_map_index.find(val1)->second);
            result.push_back(val_map_index.find(val2)->second);
        }

        std::sort(result.begin(), result.end());

        return result;
    }
};
