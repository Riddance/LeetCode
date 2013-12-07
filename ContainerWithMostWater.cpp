//brute force solution
class Solution {
public:
    int maxArea(vector<int> &height) {

    	int max_water = 0;

    	for (int i = 0; i < (int)height.size(); ++i)
    	{
    		for (int j = 0; j < (int)height.size(); ++j)
    		{
    			if (i >= j)
    				continue;

    			int lhs = height[i];
    			int rhs = height[j];

    			int cur_water = min(lhs, rhs) * abs(i - j);

    			if (cur_water > max_water)
    				max_water = cur_water;
    		}
    	}
        
    }
};