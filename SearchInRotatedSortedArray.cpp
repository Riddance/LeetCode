class Solution {
public:
    int search(int A[], int n, int target) {
    	int mid = 0;
    	int low = 0;
    	int high = n - 1;

    	while (low <= high) {
    		mid = (low + high) / 2;
    		if (A[mid] == target) {
    			return mid;
    		}
    		else if ((target < A[mid] && A[high] > A[mid]) ||
    			(target < A[mid] && A[mid] > A[low] && target >= A[low]) ||
    			(target > A[mid] && target > A[high] && A[mid] <= A[high])) {
    			high = mid - 1;
    		}
    		else {
    			low = mid + 1;
    		}
    	}

    	return -1;
    }
};