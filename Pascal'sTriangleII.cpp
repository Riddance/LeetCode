class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        result.resize(rowIndex + 1, 1);

        if ( rowIndex == 0 || rowIndex == 1)
            return result;

        vector<int> pre_result = getRow(rowIndex - 1);
        
        for (int i = 1; i < rowIndex; ++i){
            result[i] = pre_result[i] + pre_result[i - 1];
        }

        return result;        
    }
};