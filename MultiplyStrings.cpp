class Solution {
public:
    string multiply(string num1, string num2) {
        string resStr = "0";

        int size1 = num1.size();
        int size2 = num2.size();

        if (size1 == 0 || size2 == 0) {
            return resStr;
        }

        if (num1 == "0" || num2 == "0") {
            return resStr;
        }

        for (int i = size1 - 1; i >= 0; --i) {
            int carry = 0;
            string tmpStr;

            if (num1[i] == '0') {
                continue;
            }

            for (int j = size2 - 1; j >= 0; --j) {
                int val = (num1[i] - '0') * (num2[j] - '0') + carry;
                tmpStr.insert(tmpStr.begin(), val % 10 + '0');

                carry = val / 10;
            }

            if (carry) {
                tmpStr.insert(tmpStr.begin(), carry + '0');
            }

            if (tmpStr != "0") {
                tmpStr  = tmpStr + string(size1 - 1 - i, '0');
            }

            //wil add tmpStr to resStr
            int lpos = resStr.size();
            int rpos = tmpStr.size();
            carry = 0;
            while (lpos && rpos) {
                int val = (resStr[lpos - 1] - '0') + (tmpStr[rpos - 1] - '0') + carry;
                resStr[lpos - 1] = val % 10 + '0';
                carry = val / 10;

                --lpos;
                --rpos;
            }

            while (lpos) {
                int val = (resStr[lpos - 1] - '0') + carry;
                resStr[lpos - 1] = val % 10 + '0';
                carry = val / 10;
                --lpos;
            }

            while (rpos) {
                int val = (tmpStr[rpos - 1] - '0') + carry;
                resStr.insert(resStr.begin(), val % 10 + '0');

                carry = val / 10;
                --rpos;
            }

            if (carry) {
                resStr.insert(resStr.begin(), carry + '0');
            }
        }

        return resStr;
    }
};