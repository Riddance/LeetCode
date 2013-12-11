
 // Definition for an interval.
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    	std::vector<Interval> merged_intervals;

    	struct CmpInterval
    	{
    		bool operator()(Interval lhs, Interval rhs)
    		{
    			return lhs.start < rhs.start;
    		}

    	}cmp_interval;

    	std::sort(intervals.begin(), intervals.end(), cmp_interval);

    	Interval cur_interval;

    	if (intervals.size())
    	{
    		cur_interval.start = intervals[0].start;
    		cur_interval.end = intervals[0].start;
    	}
    	else
    	{
    	    goto out;
    	}

    	for (int i = 0; i < (int)intervals.size(); ++i)
    	{
    		if (cur_interval.end >= intervals[i].start)
    		{
    			cur_interval.end = max(cur_interval.end, intervals[i].end);
    		}
    		else
    		{
    			merged_intervals.push_back(cur_interval);
    			cur_interval = intervals[i];
    		}
    	}
    	
    	merged_intervals.push_back(cur_interval);

    	out:
    	
    	return merged_intervals;
    }
};