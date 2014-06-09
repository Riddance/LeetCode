class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = m + n;

        while (m || n) {
            int *pA = NULL;
            int *pB = NULL;

            if (m) pA = A + m - 1;
            if (n) pB = B + n - 1;
            if (pA == NULL) {
                A[(cur--) - 1] = B[(n--) - 1];
                continue;
            }

            if (pB == NULL) {
                A[(cur--) - 1] = A[(m--) - 1];
                continue;
            }

            if (*pA < *pB) {
                A[(cur--) - 1] = B[(n--) - 1];
                continue;
            }

            A[(cur--) - 1] = A[(m--) - 1];
        }

        return;
    }
};
