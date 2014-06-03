class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int quotient = 0;
        long long int sign = 0;

        long long int dividend_ = dividend;
        long long int divisor_ = divisor;

        if (dividend_ > 0 && divisor_ > 0)
            sign = 0;
        else if (dividend_ < 0 && divisor_ < 0)
        {
            sign = 0;
            dividend_ = -dividend_;
            divisor_ = -divisor_;
        }
        else if (dividend_ > 0 && divisor_ < 0)
        {
            sign = 1;
            divisor_ = -divisor_;
        }
        else if (dividend_ < 0 && divisor_ > 0)
        {
            sign = 1;
            dividend_ = -dividend_;
        }
        else
            return 0;

        long long int key = divisor_;
        long long int value = 1;

        while (dividend_ >= key)
        {
            dividend_ = dividend_ - key;
            key = key << 1;

            quotient = quotient + value;
            value = value << 1;
        }

        while (dividend_ >= divisor_)
        {
            if (dividend_ < key && key > divisor_)
            {
                key = key >> 1;
                value = value >> 1;
                continue;
            }

            dividend_ = dividend_ - key;
            quotient = quotient + value;
        }

        if (sign)
            return -quotient;
        else
            return quotient;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;

        int result = 0;

        long long int lhs = dividend;
        long long int rhs = divisor;
        if (lhs < 0) {
            lhs = -lhs;
            sign = -sign;
        }

        if (rhs < 0) {
            rhs = -rhs;
            sign = -sign;
        }

        long long int key = rhs;
        long long int val = 1;

        while (lhs >= rhs) {
            if (key < rhs) {
                break;
            }

            if (key <= lhs) {
                lhs = lhs - key;
                result = result + (int)val;
            }

            if (key < lhs) {
                key = key << 1;
                val = val << 1;
            }

            if (key > lhs) {
                key = key >> 1;
                val = val >> 1;
            }
        }

        return sign < 0 ? -result : result;
    }
};
