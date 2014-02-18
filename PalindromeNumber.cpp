class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int cnt = 0;

        int t = x;
        while (t = t / 10) {
            ++cnt;
        }

        while (cnt > 0) {
            int lhs = x / ((int)pow(10, cnt));
            int rhs = x % 10;

            if (lhs != rhs) {
                return false;
            }

            x = x / 10;
            x = x - lhs * ((int)pow(10, --cnt));
            --cnt;
        }

        return true;
    }
};