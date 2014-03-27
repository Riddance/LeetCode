/************************************************************************/
/* Problem  : Longest Palindromic Substring                             */
/* Author   : yixiongx@gmail.com                                        */
/* Time     : 2013.12.05                                                */
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
        int pos_start = 0;
        int str_size = 0;

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
                    is_palindrome[j][j] = true;
                }
                else if (i == 1)
                {
                    is_palindrome[j][j + i] = (s[j] == s[j + i]);
                }
                else
                {
                    is_palindrome[j][j + i] = is_palindrome[j + 1][j + i - 1] && (s[j] == s[j + i]);
                }

                if (i + 1 > str_size && is_palindrome[j][j + i])
                {
                    pos_start = j;
                    str_size = i + 1;
                }

            }
        }
        
        return string(s, pos_start, str_size);
    }
};

//O(N2) Time and O(1) Space Solution
class Solution {
public:
    string longestPalindrome(string s) {

        string longest_palindrome;

        for (size_t i = 0; i < s.size(); ++i)
        {
            string cur_palindrome = get_expand_palindrome_str(s, i, i);

            if (cur_palindrome.size() > longest_palindrome.size())
            {
                longest_palindrome = cur_palindrome;
            }

            cur_palindrome = get_expand_palindrome_str(s, i, i + 1);

            if (cur_palindrome.size() > longest_palindrome.size())
            {
                longest_palindrome = cur_palindrome;
            }
        }

        return longest_palindrome;
    }

    string get_expand_palindrome_str(string s, size_t l, size_t r)
    {
        size_t s_size = s.size();

        while (l >= 0 && r < s.size() && l <= r && s[l] == s[r])
        {
            --l;
            ++r;
        }

        return string(s, l + 1, r - 1 - l);
    }
};

//O(1) Time Solution
class Solution
{
public:
    string longestPalindrome(string s) {
        
        string pad_string = padding_string(s);

        int *p = new int[pad_string.size()];

        int center = 0;
        int rhs_edge = 0;

        for (int i = 0; i < (int)pad_string.size(); ++i)
        {
            int mirror_i = center * 2 - i;

            p[i] = rhs_edge  > i ? min(p[mirror_i], rhs_edge - i) : 0;

            while ( i - p[i] - 1 >= 0 && (pad_string[i - p[i] - 1] == pad_string[i + p[i] + 1]))
                p[i]++;

            if (p[i] + i > rhs_edge)
            {
                center = i;
                rhs_edge = p[i] + i;
            }
        }

        int palin_size = 0;
        int index = 0;

        for (int i = 0; i < (int)pad_string.size(); ++i)
        {
            if (p[i] > palin_size)
            {
                palin_size = p[i];
                index = i;
            }
        }

        if (p)
        {
            delete [] p;
            p = NULL;
        }

        return string(s, (index - palin_size) / 2, palin_size);
    }

    string padding_string(string s)
    {
        string pad_string;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            pad_string = pad_string + "#" + s[i];
        }

        return pad_string += "#";
    }

};
