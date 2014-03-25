class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int close_sum	= 0;
        int min_diff	= INT_MAX;

        if ((int)num.size() <= 3) {

        	auto Iter = num.begin();
        	while (Iter != num.end()) {
        		close_sum += (*Iter);
        		++Iter;
        	}

        	return close_sum;
        }

        std::sort(num.begin(), num.end(), std::less<int>());

        for (int i = 0; i < (int)num.size(); ++i) {
        	int lhs = i + 1;
        	int rhs = (int)num.size() - 1;

        	if (i > 0 && num[i] == num[i - 1]) {
        		continue;
        	}

        	while (lhs < rhs) {
        		int val = num[i] + num[lhs] + num[rhs];
        		int diff = abs(val - target);

        		if (diff == 0) {
        			return target;
        		}

        		if (diff < min_diff) {
        			min_diff = diff;
        			close_sum = val;
        		}

        		if (val < target) {
        			++lhs;
        		}
        		else {
        			--rhs;
        		}
        	}

        }

        return close_sum;
    }
};