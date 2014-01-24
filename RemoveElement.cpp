class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int* cur = A;
        int i = 0;
        while (i < n) {
            if (A[i] != elem) {
                *cur++ = A[i];
            }
            ++i;
        }
        
        return int(cur - A);
    }
};