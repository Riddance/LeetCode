class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int array_size = (int)nums.size();
		int max_product = INT_MIN;
		int cur_product = 1;

		int pre_product = INT_MIN;
		for (int i = 0; i < array_size; ++i) {
			if (nums[i] != 0) {
				cur_product = cur_product * nums[i];
				max_product = std::max(max_product, cur_product);
			}
			else {
				max_product = std::max(max_product, 0);
			}

			if (nums[i] < 0 && cur_product < 0) {
				pre_product = std::max(pre_product, cur_product);
			}

			if (nums[i] == 0) {
				cur_product = 1;
				pre_product = INT_MIN;
			}

			if (((i + 1 < array_size) && nums[i + 1] == 0) || i == array_size - 1) {
				if (cur_product < 0 && cur_product != nums[i]) {
					max_product = std::max(max_product, cur_product / pre_product);
				}
				cur_product = 1;
				pre_product = INT_MIN;
			}
		}

		return max_product;
	}
};
