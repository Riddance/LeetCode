class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        std::vector<std::vector<int> > rv;

        if ((int)S.size() == 0) {
        	goto out;
        }

        std::sort(S.begin(), S.end(), std::less<int>());

        for (int i = 0; i < (int)S.size() - 1; ++i) {
        	for (int j = i + 1; j < (int)S.size(); ++j) {
        		std::vector<int> r(;

        	}
        }

    out:
    	std::vector<int> r;
    	rv.push_back(r);

    	return rv;
    }
};
