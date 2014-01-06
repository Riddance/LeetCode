/************************************************************************/
/* Problem  : String To integer                                         */
/* Author   : yixiongx@gmail.com                                        */
/* Time     : 2013.12.10                                                */
/************************************************************************/


class Solution {
public:
    int atoi(const char *str) {
        int integer = 0;
        int flag = 0;

        int str_size = (int)strlen(str);
        int i = 0;

        while (i < str_size) {
            if (isblank(str[i]) && !flag) {
                ++i;
                continue;
            }

            if (str[i] == '+' && !flag) {
                ++i;
                flag = 1;
                continue;
            }

            if (str[i] == '-' && !flag) {
                ++i;
                flag = -1;
                continue;
            }

            if (!flag)
                flag = 1;

            if (isdigit(str[i]) && flag) {
                if (flag == 1 && (INT_MAX - (str[i] - '0')) / 10 < integer) {
                    integer = INT_MAX;
                    goto out;
                }

                if (flag == -1 && (INT_MIN + (str[i] - '0')) / 10 > integer * (-1)) {
                    integer = INT_MIN;
                    goto out;
                }

                integer = integer * 10 + (str[i] - '0');
                ++i;
                continue;
            }

            break;
        }

        integer = integer * flag;

        out:
        return integer;
    }
};