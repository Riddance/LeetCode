class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        if (n == 0)
            return 0;

        int curnumber = 2;
        int prevnumber = 1;

        for (int i = 3; i <=n; ++i)
        {
            int temp = curnumber;
            curnumber = curnumber + prevnumber;
            prevnumber = temp;
        }

        return curnumber;
    }
};
