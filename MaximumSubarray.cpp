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

//O(n) Solution
class Solution {
public:
    int maxSubArray(int A[], int n) {
        std::vector<int> s(n, 0);
        int m = 0;
        m = s[0] = A[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] > 0 ? (A[i] + s[i - 1]) : A[i];
            m = max(m, s[i]);
        }

        return m;
    }
};