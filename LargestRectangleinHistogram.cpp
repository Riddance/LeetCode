class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	if (height.size() == 0) {
    		return 0;
    	}

    	int largest_area = 0;

    	std::stack<int> index_stack;
    	std::stack<int> height_stack;

    	for (int i = 0; i < (int)height.size(); ++i) {
    		if (index_stack.empty() || height[i] >= height_stack.top()) {
    			index_stack.push(i);
    			height_stack.push(height[i]);
    		}
    		else if (index_stack.empty() == false && height[i] < height_stack.top()){
                int area  = 0;
                int index = 0;

    			while (index_stack.empty() == false && height[i] < height_stack.top()) {
                    index        = index_stack.top();
                    area         = (i - index) * height_stack.top();
                    largest_area = max(area, largest_area);
                    
    				index_stack.pop();
    				height_stack.pop();
    			}

    			index_stack.push(index);
    			height_stack.push(height[i]);
    		}
    	}

    	while (index_stack.empty() == false) {
            int area     = height_stack.top() * (height.size() - index_stack.top());
            largest_area = max(area, largest_area);

    		height_stack.pop();
    		index_stack.pop();
    	}

    	return largest_area;
    }
};