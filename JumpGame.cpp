class Solution {
public:
    void helpFunction(int A[], int n, int l, vector<int>& jump_array) {

        if (l + A[l] >= n - 1) {
            jump_array[l] = 1;
            return;
        }

        for (int i = 1; i <= A[l]; ++i) {
            if (jump_array[l + i] == -1) {
                helpFunction(A, n, l + i, jump_array);
            }

            if (jump_array[l + i] == 1) {
                jump_array[l] = 1;
                return;
            }
        }

        jump_array[l] = 0;
        return;
    }

    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> jump_array(n, -1);

        helpFunction(A, n, 0, jump_array);

        return jump_array[0] == 1;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        int can_reach = 0;
        for (int i = 0; i < n && i <= can_reach; ++i) {
            if (i + A[i] > can_reach) can_reach = i + A[i];
            if (can_reach >= n - 1) return true;
        }

        return can_reach >= n - 1;
    }
};

