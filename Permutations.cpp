class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > results;
        
        sort(num.begin(), num.end());
        
        results.push_back(num);
        
        while (get_next_permute(num)) results.push_back(num);
        
        return results;
    }
    
    bool get_next_permute(vector<int> &num) {
        int m = 0;
        int i = 0;

        int num_count = num.size();

        for (i = num_count - 2; i >= 0; --i) {
            if (num[i] < num[i + 1])
                break;
        }

        if (i < 0)
            return false;

        m = i;
        ++i;

        int min_i = i;
        int min_num = num[min_i];

        for (; i < num_count; ++i) {
            if (num[i] < min_num && num[i] > num[m]) {
                min_i = i;
                min_num = num[min_i];
            }
        }

        std::swap(num[min_i], num[m]);
        sort(num.begin() + m + 1, num.end());

        return true;
    }
};
