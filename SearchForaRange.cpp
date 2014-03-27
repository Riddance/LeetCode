class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        std::vector<int> vec_range = {-1, -1};
        int low, high, mid;

        low = 0;
        high = n - 1;
        //Get Lower limit
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > target) {
                high = mid - 1;
            }
            else if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                if (mid > 0 && A[mid - 1] == target) {
                    high = mid - 1;
                }
                else {
                    vec_range[0] = mid;
                    break;
                }
            }
        }

        low = 0;
        high = n - 1;
        //Get High limit
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > target) {
                high = mid - 1;
            }
            else if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                if (mid < n - 1 && A[mid + 1] == target) {
                    low = mid + 1;
                }
                else {
                    vec_range[1] = mid;
                    break;
                }
            }
        }

        if (vec_range[0] == -1 && vec_range[1] != -1)
            vec_range[0] = vec_range[1];

        if (vec_range[0] != -1 && vec_range[1] == -1)
            vec_range[1] = vec_range[0];
        
        return vec_range;
    }
};