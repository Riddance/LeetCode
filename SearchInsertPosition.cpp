class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        
        for (; i < n; ++i) {
            if (A[i] >= target)
            return i;
        }
        
        return i;
    }
};
