class Solution {
public:
    int findMin(vector<int>& nums) {
        int lhs = 0;
        int rhs = (int)nums.size() - 1;

        while (rhs - lhs > 1) {
            int mid = (rhs + lhs) / 2;

            if (nums[lhs] < nums[mid] && nums[mid] < nums[rhs]) {
                break;
            }
            else if (nums[lhs] > nums[mid]) {
                rhs = mid;
            }
            else {
                lhs = mid;
            }
        }

        return std::min(nums[lhs], nums[rhs]);
    }
};
