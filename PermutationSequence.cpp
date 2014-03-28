class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        std::string numStr;

        for (int i = 1; i <= n; ++i) {
        	numStr.push_back('0' + i);
        }

        for (int i = 0; i < k; ++i) {
        	if (!getNextPermutationString(numStr)) {
        		break;
        	}
        }

        return numStr;
    }

    bool getNextPermutationString(std::string &Str) {
    	int strSize = Str.size();

    	int i = strSize - 2
    	
    	for (; i >= 0; --i) {
    		if ( Str[i] < Str[i + 1]) {
    			break;
    		}
    	}

    	if (i < 0) {
    		return false;
    	}

    	return true;
    }
};
