class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int cur_pos = 0;
        int pre_pos = 0;

        int mov_stp = -1;

        if (n <= 0) return 0;

        pre_pos = 0;
        cur_pos = pre_pos + 1;

        while (cur_pos < n) {
            if (A[pre_pos] == A[cur_pos]) {
                cur_pos++;
                mov_stp++;
                continue;
            }

            if (mov_stp > 0) {
                for (int i = cur_pos; i < n; i++) A[i - mov_stp] = A[i];
                    
                cur_pos = cur_pos - mov_stp;
                n = n - mov_stp;
            }

            mov_stp = -1;
            pre_pos = cur_pos;
            cur_pos++;
        }

        if (mov_stp > 0) n = n - mov_stp;

        return n;
    }
};