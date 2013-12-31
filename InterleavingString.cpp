class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if (s1.size() + s2.size() != s3.size())
    		return false;

    	if (s1.empty() && s2.empty() && s3.empty())
    		return true;

    	if (s1.empty())
    		return s2 == s3;

    	if (s2.empty())
    		return s1 == s3;

    	return s1.front() == s3.front() &&         
    }
};