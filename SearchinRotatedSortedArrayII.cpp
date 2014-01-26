class Solution {
public:
    bool search(int A[], int n, int target) {
    	int mid = 0;
    	int low = 0;
    	int high = n - 1;

    	while (low <= high) {
    		mid = (low + high) / 2;
    		if (A[mid] == target) {
    			return true;
    		}
    		else if ((target < A[mid] && target >= A[low]) ||
    			(target > A[mid] && target > A[high])){
    			high = mid - 1;
    		}
    		else {
    			low = mid + 1;
    		}

    	}

    	return false;
    }
};