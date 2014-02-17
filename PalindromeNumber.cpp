class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0)
    		return false;

    	int cnt = 0;
    	while (x) {
    		++cnt;
    		x = x / 10;
    	}

    	int lhs, rhs;
    	lhs = i - 1;
    	rhs = 0;

    	while (lhs >= rhs) {
    		int lvalue = x / ((int)pow(10, lhs));
    		int rvalue = x % 10;

    		if (lvalue != rvalue)
    			return false;

    		--lhs;
    		++rhs;

    		x = x / 10;
    		x = x - lvalue * ((int)pow(10, lhs));
    	}

    	return true;
    }
};