class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test  case.
        vector<vector<int> > results;

        for (int i = 0; i < numRows; ++i) {
            vector<int> result;
            result.resize(i + 1, 1);

            if (i == 0 || i == 1) {
                results.push_back(result);
                continue;
            }

            for (int j = 1; j < i; ++j) {
                vector<int> pre_result = results.back();
                result[j] = pre_result[j - 1] + pre_result[j];
            }

            results.push_back(result);
        }

        return results;
    }
};
