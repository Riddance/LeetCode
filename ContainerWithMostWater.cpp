/************************************************************************/
/* Problem  : Container With Most Water                                 */
/* Author   : yixiongx@gmail.com                                        */
/* Time     : 2013.12.08                                                */
/************************************************************************/

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
        
        return max_water;
    }
};

//O(n) solution
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_water = 0;

        std::multimap<int, int, std::less<int> > height_to_index;
        std::set<int, std::less<int> > index_set;

        for (int i = 0; i < (int)height.size(); ++i)
        {
            height_to_index.insert(make_pair(height[i], i));
            index_set.insert(i);
        }

        std::map<int, int, std::less<int> >::iterator cur_iter = height_to_index.begin();
        while (cur_iter != height_to_index.end())
        {
            int max_diff_index = 0;

            if (abs(cur_iter->second - *index_set.begin()) > abs(cur_iter->second - *index_set.rbegin()))
            {
                max_diff_index = *index_set.begin();
            }
            else
            {
                max_diff_index = *index_set.rbegin();
            }

            int cur_water = abs(max_diff_index - cur_iter->second) * cur_iter->first;

            if (cur_water > max_water)
                max_water = cur_water;

            index_set.erase(cur_iter->second);
            ++cur_iter;
        }

        return max_water;
    }
};