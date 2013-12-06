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
                string(sub_string.begin() + 1, sub_string.end() - 2), 
                *sub_string.begin() == *(sub_string.end() - 1)
            );
        }
    }
};

//DP Solution O(n3)
class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome;

        int lcs_size[1000][1000];

        for (size_t i = 0; i < s.size(); ++i)
        {
            for (size_t j = 0; j < s.size(); ++j)
            {
                if (s[i] == s[s.size() - 1 - j])
                {
                    if (i == 0 || j == 0)
                    {
                        lcs_size[i][j] = 1;
                    }
                    else
                    {
                        lcs_size[i][j] = lcs_size[i - 1][j - 1] + 1;
                    }

                    string cur_lcs = string(s, i - lcs_size[i][j] + 1, i);

                    if (cur_lcs.size() > palindrome.size() && i != j)
                    {
                        palindrome = cur_lcs;
                    }
                    else if (cur_lcs.size() > palindrome.size() && IsPalindrome(cur_lcs, true))
                    {
                        palindrome = cur_lcs;
                    }

                } 
                else
                {
                    lcs_size[i][j] = 0;
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
                string(sub_string.begin() + 1, sub_string.end() - 2), 
                *sub_string.begin() == *(sub_string.end() - 1)
            );
        }
    }
};

//DP Solution O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome;
        palindrome.clear();

        bool is_palindrome[1000][1000] = {false};

        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if (j + i > s.size() - 1)
                {
                    continue;
                }

                if (i == 0)
                {
                    is_palindrome[j][j] == true;
                }
                else if (i == 1)
                {
                    is_palindrome[j][j + i] = (s[j] == s[j + i]);
                }
                else
                {
                    is_palindrome[j][j + i] = is_palindrome[j + 1][j + i - 1] && (s[j] == s[j + i]);
                }

                if (is_palindrome[j][j + i] && i + 1 > palindrome.size())
                {
                    palindrome = string(s, j, j + i);
                }

            }
        }

        return palindrome;
    }
};