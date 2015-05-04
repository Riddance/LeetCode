class Solution {
public:
    int findMin(vector<int>& nums) {
        return helpFunction(nums, 0, (int)nums.size() - 1);
    }

    int helpFunction(vector<int>& nums, int lhs, int rhs) {
        if (rhs - lhs <= 1) {
            return std::min(nums[lhs], nums[rhs]);
        }

        int mid = (lhs + rhs) / 2;
        if (nums[mid] == nums[lhs] && nums[mid] == nums[rhs]) {
            return std::min(helpFunction(nums, lhs, mid), helpFunction(nums, mid + 1, rhs));
        }
        else if (nums[lhs] == nums[mid]) {
            return helpFunction(nums, mid, rhs);
        }
        else if (nums[mid] == nums[rhs]){
            return helpFunction(nums, lhs, mid);
        }
        else if (nums[lhs] < nums[mid] && nums[mid] < nums[rhs]) {
            return nums[lhs];
        }
        else if (nums[lhs] < nums[mid]) {
            return helpFunction(nums, mid, rhs);
        }
        else {
            return helpFunction(nums, lhs, mid);
        }
    }
};
