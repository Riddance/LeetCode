class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int result = 0;

        for (int i = 0; i < n; ++i) {
            while (A[i] != i + 1) {
                if (A[i] > n || A[i] <= 0 || A[i] == i + 1) {
                    break;
                }

                if (A[i] == A[A[i] - 1]) {
                    break;
                }

                std::swap(A[i], A[A[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                result = i + 1;
                break;
            }
        }

        if (result == 0) {
            result = n + 1;
        }

        return result;
    }
};
