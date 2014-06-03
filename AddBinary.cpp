class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string result;
        result.clear();

        int carry_bit = 0;

        int a_size = (int)a.size();
        int b_size = (int)b.size();

        while (a_size > 0 && b_size > 0)
        {
            int a_num = a[a_size - 1] - '0';
            int b_num = b[b_size - 1] - '0';
            int cur_bit = (a_num + b_num + carry_bit) % 2;
            carry_bit = (a_num + b_num + carry_bit) / 2;

            --a_size;
            --b_size;
            char temp = '0' + cur_bit;

            result.insert(result.begin(), 1, temp);
        }

        while (a_size > 0)
        {
            int a_num = a[a_size - 1] - '0';
            int cur_bit = (a_num + carry_bit) % 2;
            carry_bit = (a_num + carry_bit) / 2;

            --a_size;
            char temp = '0' + cur_bit;

            result.insert(result.begin(), 1, temp);
        }

        while (b_size > 0)
        {
            int b_num = b[b_size - 1] - '0';
            int cur_bit = (b_num + carry_bit) % 2;
            carry_bit = (b_num + carry_bit) / 2;

            --b_size;
            char temp = '0' + cur_bit;

            result.insert(result.begin(), 1, temp);
        }

        if (carry_bit)
        {
            char temp = '0' + carry_bit;

            result.insert(result.begin(), 1, temp);
        }

        return result;
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string result;
        result.clear();

        int cur_bit = 0;
        int carry_bit = 0;

        while (!a.empty() || !b.empty()) {
            int bit_a = 0;
            int bit_b = 0;

            if (!a.empty()) {
                bit_a = a.back() - '0';
                a.pop_back();
            }

            if (!b.empty()) {
                bit_b = b.back() - '0';
                b.pop_back();
            }

            cur_bit = (bit_a + bit_b + carry_bit) % 2;
            carry_bit = (bit_a + bit_b + carry_bit) / 2;

            result.insert(result.begin(), 1, cur_bit + '0');
        }

        if (carry_bit) {
            result.insert(result.begin(), 1, carry_bit + '0');
        }
        
        return result;
    }
};
