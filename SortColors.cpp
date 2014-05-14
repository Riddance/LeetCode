class Solution {
public:
    void sortColors(int A[], int n) {

    	vector<int> v(3, 0);

    	for (int i = 0; i < n; ++i) {
    		v[A[i]]++;
    	}

    	for (int i = 0; i < v[0]; ++i) {
    		*A++ = 0;
    	}

    	for (int i = 0; i < v[1]; ++i) {
    		*A++ = 1;
    	}

    	for (int i = 0; i < v[2]; ++i) {
    		*A++ = 2;
    	}

    	return;
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {

    	int r = -1;
    	int g = -1;
    	int b = -1;

    	for (int i = 0; i < n; ++i) {
    		if (A[i] == 0) {
    			A[++b] = 2;
    			A[++g] = 1;
    			A[++r] = 0;
    		}
    		else if (A[i] == 1) {
    			A[++b] = 2;
    			A[++g] = 1;
    		}
    		else {
    			A[++b] = 2;
    		}
    	}

    	return;
    }
};