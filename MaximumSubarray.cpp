// Use Divide and Conquer approach
class Solution {
public:
    int maxSubArray(int A[], int n) {
    	return getMaxSubArrayValue(A, 0, n - 1);
    }

    int getMaxSubArrayValue(int A[], int lhs, int rhs) {
    	if (lhs == rhs) {
    		return A[lhs];
    	}

    	assert(lhs < rhs);

    	int mid = lhs + (rhs - lhs) / 2;

    	int leftMax = getMaxSubArrayValue(A, lhs, mid);
    	int rightMax = getMaxSubArrayValue(A, mid + 1, rhs);

    	int lvalue = A[mid];
    	int rvalue = A[mid + 1];

    	int temp = 0;
    	for (int i = mid; i >= lhs; --i) {
    		temp = temp + A[i];
    		if (temp > lvalue) {
    			lvalue = temp;
    		}
    	}

    	temp = 0;
    	for (int i = mid + 1; i <= rhs; ++i) {
    		temp = temp + A[i];
    		if (temp > rvalue) {
    			rvalue = temp;
    		}
    	}

    	return max(max(leftMax, rightMax), lvalue + rvalue);
    }
};