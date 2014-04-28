class Solution {
public:
    string intToRoman(int num) {
        string romanStr;

        if (num < 0 || num > 3999) {
            return romanStr;
        }

        int thousand, hundred, ten, digit;

        thousand = num / 1000;
        num = num % 1000;
        romanStr += string(thousand, 'M');

        hundred = num / 100;
        num = num % 100;
        if (hundred >= 0 && hundred <= 3) {
            romanStr += string(hundred, 'C');
        }
        else if (hundred == 4) {
            romanStr += "CD";
        }
        else if (hundred == 9) {
            romanStr += "CM";
        }
        else {
            romanStr += "D";
            romanStr += string(hundred - 5, 'C');
        }

        ten = num / 10;
        num = num % 10;
        if (ten >= 0 && ten <= 3) {
            romanStr += string(ten, 'X');
        }
        else if (ten == 4) {
            romanStr += "XL";
        }
        else if (ten == 9) {
            romanStr += "XC";
        }
        else {
            romanStr += "L";
            romanStr += string(ten - 5, 'X');
        }

        digit = num;
        if (digit >= 0 && digit <= 3) {
            romanStr += string(digit, 'I');
        }
        else if (digit == 4) {
            romanStr += "IV";
        }
        else if (digit == 9) {
            romanStr += "IX";
        }
        else {
            romanStr += "V";
            romanStr += string(digit - 5, 'I');
        }

        return romanStr;
    }
};
