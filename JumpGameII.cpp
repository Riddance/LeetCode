class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int s = 0;
        int l = n - 1;

        if (n <= 1)
            goto out;
            
        s = 1;
        while (l > A[0]) {
            int m = l;
            for (int i = l; i >= 0; --i) {
                if ((l - i) <= A[i] && i < l)
                    m = i;
            }
            l = m;
            ++s;
        }

        out:
        return s;
    }
};