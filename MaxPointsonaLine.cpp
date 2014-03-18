struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {

    	if (points.size() <= 2)
    		return points.size();

    	int max_count = 0;
    	int same_count = 0;

    	struct Cmp {
    		bool operator()(const double lhs, const double rhs) const {
    			return fabs(lhs - rhs) <= 0.000001;
    		}
    	};

    	std::unordered_map<double, int, std::hash<double>, Cmp> GradientMap;
    	std::unordered_map<int, int> Xmap;

    	for (int i = 0; i < (int)points.size() - 1; ++i) {
    		for (int j = i + 1; j < (int)points.size(); ++j) {

    			if (points[i].x == points[j].x && points[i].y == points[j].y) {
    				if (same_count == 0) {
    					same_count = 2;
    				}
    				else {
    					same_count++;
    				}

    				continue;
    			}

    			if (points[i].x == points[j].x) {
    				if (Xmap.find(points[i].x) == Xmap.end()) {
    					Xmap[points[i].x] = 2;
    				}
    				else {
    					Xmap[points[i].x]++;
    				}

    				continue;
    			}

    			double gradient = ((double)points[i].y - points[j].y) / ((double)points[i].x - points[j].x);

    			if (GradientMap.find(gradient) == GradientMap.end()) {
    				GradientMap[gradient] = 2;
    			}
    			else {
    				GradientMap[gradient]++;
    			}
    		}
    	}

    	auto IterG = GradientMap.begin();
    	while (IterG != GradientMap.end()) {
    		if (IterG->second > max_count) {
    			max_count = IterG->second;
    		}

    		IterG++;
    	}

    	auto IterX = Xmap.begin();
    	while (IterX != Xmap.end()) {
    		if (IterX->second > max_count) {
    			max_count = IterX->second;
    		}

    		IterX++;
    	}

    	if (same_count > max_count) {
    		max_count = same_count;
    	}

    	return max_count;
    }
};