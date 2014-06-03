class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        stack<int> operand_stack;

        while (!tokens.empty())
        {
            vector<string>::iterator Iter = tokens.begin();
            if ((*Iter).size() == 1 && ((*Iter)[0] == '+' || (*Iter)[0] == '-' || (*Iter)[0] == '*' || (*Iter)[0] == '/'))
            {
                assert(operand_stack.size() >= 2);

                int rhs = operand_stack.top();
                operand_stack.pop();

                int lhs = operand_stack.top();
                operand_stack.pop();

                switch ((*Iter)[0])
                {
                case '+':
                    operand_stack.push(lhs + rhs);
                    break;
                case '-':
                    operand_stack.push(lhs - rhs);
                    break;
                case '*':
                    operand_stack.push(lhs * rhs);
                    break;
                case '/':
                    operand_stack.push(lhs / rhs);
                    break;
                default:
                    assert(0);
                    break;
                }
            }
            else
            {
                operand_stack.push(stoi(*Iter));
            }

            tokens.erase(Iter);
        }
        
        if (!operand_stack.empty())
            result = operand_stack.top();

        return result;
    }
};
