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
    		else if ((A[mid] > target && target >= A[low]) ||
    		(A[mid] < target && A[high] < target)) {
    	}

    	return -1;
    }
};