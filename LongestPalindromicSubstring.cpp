/************************************************************************/
/* Problem   : Longest Palindromic Substring					        */
/* Author	 : yixiongx@gmail.com										*/
/* Time      : 2013.12.05												*/
/************************************************************************/

//Brute force Solution
class Solution {
public:
    string longestPalindrome(string s) 
    {
    	string palindrome;

    	for (size_t i = 0; i < s.size() - 1; ++i)
    	{
    		for (size_t j = 0; j < s.size() - 1; ++j)
    		{
    			if (i > j)
    			{
    				continue;
    			}

    			string sub_string(s, i, j);

    			if (!IsPalindrome(sub_string))
    			{
    				continue;
    			}

    			if (sub_string.size() > palindrome.size())
    			{
    				palindrome = sub_string;
    			}
    		}
    	}
        
        return palindrome;
    }

    bool IsPalindrome(string sub_string, bool eq)
    {
    	if (sub_string <= 1 || eq == false)
    	{
    		return eq;
    	}

    	return IsPalindrome(
    		string(sub_string.begin() + 1, sub_string.end() - 2), 
    		*sub_string.begin() == *(sub_string.end() - 1)
        );
    }
};

//DP Solution