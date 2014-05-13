class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        helpFunction(n, n, "", result);

        return result;
    }

    void helpFunction(int leftbracket, int rightbracket, string s, vector<string>& result) {
        if (leftbracket == 0 && rightbracket == 0) {
            result.push_back(s);
            return;
        }

        if (leftbracket > 0) {
            helpFunction(leftbracket - 1, rightbracket, s + "(", result);
        }

        if (rightbracket > 0 && leftbracket < rightbracket) {
            helpFunction(leftbracket, rightbracket - 1, s + ")", result);
        }

        return;
    }
};
