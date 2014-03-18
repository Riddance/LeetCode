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

    	struct Cmp {
    		bool operator()(const double lhs, const double rhs) const {
    			return fabs(lhs - rhs) <= 0.000001;
    		}
    	};
    	std::unordered_map<double, int, std::hash<double>, Cmp> GradientMap;

        int max_point_num = 0;

    	for (int i = 0; i < (int)points.size() - 1; ++i) {
            GradientMap.clear();

            int same_point_num = 0;
            int same_X_point_num = 0;

    		for (int j = i + 1; j < (int)points.size(); ++j) {

    			if (points[i].x == points[j].x && points[i].y == points[j].y) {
    				if (same_point_num == 0) {
    					same_point_num = 2;
    				}
    				else {
    					same_point_num++;
    				}

    				continue;
    			}

    			if (points[i].x == points[j].x) {
    				if (same_X_point_num == 0) {
    					same_X_point_num = 2;
    				}
    				else {
    					same_X_point_num++;
    				}

    				continue;
    			}

    			double gradient = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);

    			if (GradientMap.find(gradient) == GradientMap.end()) {
    				GradientMap[gradient] = 2;
    			}
    			else {
    				GradientMap[gradient]++;
    			}
    		}

            if (same_X_point_num > max_point_num) {
                max_point_num = same_X_point_num;
            }

            int tmp = 0;
            auto IterG = GradientMap.begin();
            while (IterG != GradientMap.end()) {
                if (IterG->second > tmp) {
                    tmp = IterG->second;
                }

                IterG++;
            }

            if (tmp > max_point_num) {
                max_point_num = tmp;
            }

            if (tmp && (tmp + same_point_num - 1) > max_point_num) {
                max_point_num = tmp + same_point_num - 1;
            }

            if (same_point_num > max_point_num) {
                max_point_num = same_point_num;
            }
    	}

    	return max_point_num;
    }
};