// class Solution {
// public:
// 	int candy(vector<int> &ratings) {
// 	    int num = ratings.size();

// 	    int m = 0;
// 	    for (int i = 0; i < num; ++i) {
// 	        if (ratings[i] < ratings[m]) {
// 	            m = i;
// 	        }
// 	    }

// 	    vector<int> candies(num, 1);
// 	    int i = m;
// 	    do {
// 	        int p = (i - 1) % num;
// 	        int n = (i + 1) % num;

// 	        if (p < 0) {
// 	            p = num - 1;
// 	        }

// 	        if ((i % num) != 0 && ratings[i % num] < ratings[p] && candies[i % num] >= candies[p]) {
// 	            candies[p] = candies[i % num] + 1;
// 	        }

// 	        if ((i % num) != (num - 1) && ratings[i % num] < ratings[n] && candies[i % num] >= candies[n]) {
// 	            candies[n] = candies[i % num] + 1;
// 	        }

// 	        ++i;
// 	    } while ((i % num) != m);

// 	    int result = 0;
// 	    i = 0;
// 	    while (i < (int)candies.size()) {
// 	        result += candies[i];
// 	        ++i;
// 	    }

// 	    return result;
// 	}
// };

//O(n) time and O(n) space
class Solution {
public:
	int candy(vector<int> &ratings) {
		int num = ratings.size();

		vector<int> forward(num, 1);

		for (int i = 1; i < num; ++i) {
			if (ratings[i] > ratings[i - 1]) {
				forward[i] = forward[i - 1] + 1;
			}
		}

		vector<int> backward(num, 1);

		for (int i = num - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1]) {
				backward[i] = backward[i + 1] + 1;
			}
		}

		int result = 0;

		for (int i = 0; i < num; ++i) {
			result += max(forward[i], backward[i]);
		}

		return result;
	}
};

//O(n) time and O(1) space
class Solution {
public:
	int candy(vector<int> &ratings) {
	    int num = ratings.size();

	    int result      = 0;
	    int beforeAsce  = 0;
	    int curDesc     = 0;
	    int len         = 0;

	    if (num > 0) {
	        result = 1;
	    }

	    for (int i = 1; i < num; ++i) {

	        if (ratings[i] > ratings[i - 1]) {
	            if (beforeAsce == 0) {
	                beforeAsce = 1;
	            }

	            ++beforeAsce;
	            result += beforeAsce;
	            len = beforeAsce;

	            curDesc = 0;
	        }
	        else if (ratings[i] < ratings[i - 1]) {
	            if (curDesc == 0) {
	                curDesc = 1;
	            }

	            ++curDesc;
	            if (len == 0) {
	                result += curDesc;
	            }
	            else {
	                if (curDesc <= len) {
	                    result += curDesc - 1;
	                }
	                else {
	                    result += curDesc;
	                }
	            }

	            beforeAsce = 0;
	        }
	        else {
	            ++result;

	            beforeAsce = 0;
	            curDesc = 0;
	            len = 0;
	        }
	    }

	    return result;
	}
};
