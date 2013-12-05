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

    			if (!IsPalindrome(sub_string, true))
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

    //use tail recursion
    bool IsPalindrome(string sub_string, bool eq)
    {
        if (eq == false || sub_string.size() <= 1)
            return eq;
        else if (sub_string.size() == 2)
        {
            return sub_string[0] == sub_string[1];
        }
        else
        {
            return IsPalindrome(
                string(sub_string.begin() + 1, sub_string.end() - 2, 
                *sub_string.begin() == *(sub_string.end() - 1)
            );
        }


    }
};

//DP Solution

//first define array
class Solution {
public:
    string longestPalindrome(string s) {
        //record longest common substring size
        //
        int *lcs_size  = new int[s.size()][s.size()];
        
    }
};
