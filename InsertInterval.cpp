
 // Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	std::vector<Interval> merged_intervals;
    	Interval merged_interval;
    	std::vector<Interval>::iterator Iter;

    	if (intervals.size() == 0)
    	{
    		merged_intervals.push_back(newInterval);
    		goto out;
    	}

    	if (newInterval.end < intervals[0].start)
    	{
    		merged_intervals = intervals;
    		merged_intervals.insert(merged_intervals.begin(), newInterval);
    		goto out;
    	}

    	if (newInterval.start > intervals[intervals.size() - 1].end)
    	{
    		merged_intervals = intervals;
    		merged_intervals.push_back(newInterval);
    		goto out;
    	}

    	Iter = intervals.begin();
    	while (Iter != intervals.end())
    	{
    		if (Iter->end >= newInterval.start)
    		{
    			break;
    		}
    		merged_intervals.push_back(*(Iter++));
    	}

    	assert(Iter != intervals.end());

    	if (Iter->start >= newInterval.start)
    	{
    		merged_interval.start = newInterval.start;
    	}
    	else
    	{
    		merged_interval.start = Iter->start;
    	}

    	while (Iter != intervals.end())
    	{
    		if (Iter->start > newInterval.end)
    			break;

    		Iter++;
    	}

    	--Iter;
    	if (Iter->end >= newInterval.end)
    	{
    		merged_interval.end = Iter->end;
    	}
    	else
    	{
    		merged_interval.end = newInterval.end;
    	}

    	merged_intervals.push_back(merged_interval);

    	++Iter;
    	while(Iter != intervals.end())
    	{
    		merged_intervals.push_back(*(Iter++));
    	}

	out:
    	return merged_intervals;
    }
};