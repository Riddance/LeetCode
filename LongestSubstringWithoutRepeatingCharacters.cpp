/************************************************************************/
/* Problem	: Longest Substring Without Repeating Character				*/
/* Author	: yixiongx@gmail.com										*/
/* Time		: 2013.12.09												*/
/************************************************************************/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	int lss = 0;
        int lhs = 0;
        int rhs = 0;

    	int str_size = (int)s.size();

    	if (str_size <= 1)
    		return str_size;

    	while (rhs + 1 <= str_size - 1)
    	{
    		int length = 0;

    		assert(lhs <= rhs);

            size_t pos = s.find(s[rhs + 1], lhs);

            assert (pos <= rhs + 1);

            if (pos != rhs + 1)
            {
                length = rhs - lhs + 1;
                lhs = pos + 1;
            }

    		if (length > lss)
    			lss = length;

            ++rhs;
    	}
        
        if (rhs - lhs + 1 > lss)
            lss = rhs - lhs + 1;

        return lss;
    }
};