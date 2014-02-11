class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	std::vector<std::vector<int> > result;
    	if (n <= 0) {
    		return result;
    	}

    	std::vector<int> tmp(n, 0);
    	result.resize(n, tmp);

    	int value = 1;
    	int layer = 0;
    	//from the outsize to inside
    	while (layer < n / 2 + n % 2) {
    		int up, down, left, right;
    		up = left = layer;
    		down = right = n - layer - 1;

    		//for up row
    		if (up <= n - 1 && up <= down) {
    			for (int i = left; i <= right; ++i) {
    				result[up][i] = value++;
    			}
    		}

    		//the last value break
    		if (up == down && up == left) {
    			break;
    		}

    		//for right column
    		if (right >= 0 && left <= right) {
    			for (int i = up + 1; i <= down - 1; ++i) {
    				result[i][right] = value++;
    			}
    		}

    		//for the down row
    		if (down >= 0 && up < down) {
    			for (int i = right; i >= left; --i) {
    				result[down][i] = value++;
    			}
    		}

    		//for the left column
    		if (left <= n - 1 && left < right) {
    			for (int i = down - 1; i >= up + 1; --i) {
    				result[i][left] = value++;
    			}
    		}

    		++layer;
    	}
        
        return result;
    }
};