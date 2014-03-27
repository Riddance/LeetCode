
class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> index_st;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (!index_st.empty() && s[index_st.top()] == '(' && s[i] == ')')
            {
                index_st.pop();
            }
            else
            {
                index_st.push(i);
            }
        }

        int max_len = 0;

        int index_lhs = 0;
        int index_rhs = 0;
        if (s.size() > 0)
            index_rhs = s.size() - 1;

        if (index_st.empty())
            max_len = s.size();

        if (!index_st.empty())
        {
            max_len = index_rhs - index_st.top();
            index_rhs = index_st.top();
            index_st.pop();
        }

        while (!index_st.empty())
        {
            index_lhs = index_st.top();
            index_st.pop();

            max_len = max(max_len, index_rhs - index_lhs - 1);
            index_rhs = index_lhs;
        }

        max_len = max(max_len, index_rhs);

        return max_len;        
    }
};