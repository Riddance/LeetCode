class Solution {
public:
    string getSayString(string& str) {
        if (str.size() == 0) {
            return 0;
        }

        string result;

        char val = str[0];
        int count = 0;
        for (int i = 0; i < (int)str.size(); ++i) {
            if (str[i] == val) {
                ++count;
            }

            if (str[i] != val) {
                result.push_back(count + '0');
                result.push_back(val);
                count = 1;
                val = str[i];
            }

            if (i == (int)str.size() - 1) {
                result.push_back(count + '0');
                result.push_back(val);
                count = 1;
                val = str[i];
            }
        }

        return result;
    }

    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string result = "1";
        while (n > 1) {
            result = getSayString(result);
            --n;
        }

        return result;
    }
};
