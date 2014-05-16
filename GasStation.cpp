class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        assert(gas.size() == cost.size());

        int index = -1;

        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }

        for (int i = 0; i < gas.size(); NULL) {
            int sum = 0;
            int j = 0;

            for (NULL; j < gas.size(); ++j) {
                sum += gas[(i + j) % gas.size()];

                if (sum < 0) {
                    break;
                }
            }

            if (sum >= 0 && j == gas.size()) {
                index = i;
                break;
            }

            i = i + j + 1;
        }
        
        return index;
    }
};
