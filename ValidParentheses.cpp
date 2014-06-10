class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t s_size = s.length();

        stack<char> char_stack;

        for (size_t i = 0; i < s_size; ++i) {
            if (char_stack.empty()) {
                char_stack.push(s[i]);
                continue;
            }

            switch(s[i])
            {
            case ')':
                if (char_stack.top() == '(')
                    char_stack.pop();
                break;

            case '}':
                if (char_stack.top() == '{')
                    char_stack.pop();
                break;

            case ']':
                if (char_stack.top() == '[')
                    char_stack.pop();
                break;

            default:
                char_stack.push(s[i]);
            }
        }

        return char_stack.empty();
    }
};