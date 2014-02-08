class Solution {
public:
    int reverse(int x) { 
    	int r = 0;

    	while (x % 10 || x / 10) {
    		int m = x % 10;
    		if (INT_MAX / 10 + m < r) {
    			r = INT_MAX;
    			break;
    		}
    		r = r * 10 + m;
    		x = x / 10;
    	}

    	if (x < 0) {
    		if (r == INT_MAX) {
    			r = INT_MIN;
    		}
    		else {
    			r = -r;
    		}
    	}
    	
    	return r;
    }
};