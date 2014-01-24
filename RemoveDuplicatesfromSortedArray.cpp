class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        
        int *cur = A;
        int i = 1;
        while(i < n) {
            if (A[i] != *cur) {
                *(++cur) = A[i];
            }
            ++i;
        }

        return int(cur - A + 1);
    }
};