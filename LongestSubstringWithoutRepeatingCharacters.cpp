/************************************************************************/
/* Problem	: Longest Substring Without Repeating Character				*/
/* Author	: yixiongx@gmail.com										*/
/* Time		: 2013.12.09												*/
/************************************************************************/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	int lss = 0;

    	int str_size = (int)s.size();
    	int lhs = 0;
    	int rhs = 0;

    	if (str_size <= 1)
    		return str_size;

    	while (rhs + 1 <= string_size - 1)
    	{
    		int cur_length = 0;

    		asset(lhs <= rhs);

    		string cur_string(s, lhs, rhs - lhs + 1);
    		size_t find_pos = cur_string.find(s[rhs + 1])

    		if (find_pos == std::string::npos)
    			++rhs;
    		else
    		{
    			cur_length = rhs - lhs + 1;
    			lhs = find_pos + 1;
    		}

    		if (cur_length > lss)
    			lss = cur_length;
    	}
        

        return lss;
    }
};