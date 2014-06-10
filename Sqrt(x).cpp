class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        double pre_result = 0.0;
        double cur_result = 1.0;

        double sub_result = 0.0;

        do
        {
            pre_result = cur_result;
            cur_result = (pre_result + x / pre_result) / 2;
            sub_result = cur_result - pre_result;

        }while(sub_result < -0.000001 || sub_result > 0.000001);

        return (int)cur_result;
    }
};
