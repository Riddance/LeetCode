class Solution {
public:
    int trap(int A[], int n) {
        int trapped_water = 0;

        int lhs = 0;
        int rhs = n - 1;

        int lhs_max = A[lhs];
        int rhs_max = A[rhs];

        while (lhs < rhs) {
            if (lhs_max < rhs_max) {
                ++lhs;
                if (A[lhs] > lhs_max) lhs_max = A[lhs];
                else trapped_water = trapped_water + lhs_max - A[lhs];
            } 
            else {
                --rhs;
                if (A[rhs] > rhs_max) rhs_max = A[rhs];
                else trapped_water = trapped_water + rhs_max - A[rhs];
            }
        }
        
        return trapped_water;
    }
};
