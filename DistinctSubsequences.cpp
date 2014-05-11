class Solution {
public:
    int numDistinct(string S, string T) {
    	int m = S.size();
    	int n = T.size();

    	if (m < n) {
    		return 0;
    	}

    	vector<vector<int> > result(m + 1, vector<int>(n + 1, 0));
    	for (int i = 0; i <= m; ++i) {
    		result[i][0] = 1;
    	}

    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			result[i][j] = result[i - 1][j];
    			if (S[i - 1] == T[j - 1]) {
    				result[i][j] += result[i - 1][j - 1];
    			}
    		}
    	}

    	return result[m][n];
    }
};


//this Solution will TLE
class Solution {
public:
    int numDistinct(string S, string T) {
    	int num = 0;

    	if (T.size() == 0) {
    		num = 1;
    		goto out;
    	}

    	if (S.size() == 0) {
    		goto out;
    	}

    	for (int i = 0; i < S.size(); ++i) {
    		if (S[i] == T[0]) {
    			num += numDistinct(S.substr(i + 1), T.substr(1)); 
    		}
    	}

    	out:
    	return num;
  }
};