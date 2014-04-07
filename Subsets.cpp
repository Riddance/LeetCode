class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sSize = S.size();

        vector<vector<int> > VecResult;
        vector<int> r;
        VecResult.push_back(r);

        vector<vector<int> > VecSubSet;

        std::sort(S.begin(), S.end(), std::less<int>());

        if (sSize == 0) {
            goto out;
        }
        else if (sSize == 1) {
            VecSubSet.push_back(r);
        }
        else {
            vector<int> preS(S.begin(), S.begin() + sSize - 1);
            VecSubSet = subsets(preS);
        }

        for (int i = 0; i < (int)VecSubSet.size(); ++i) {
            vector<int> tmp = VecSubSet[i];

            if (tmp.empty() == false) {
                VecResult.push_back(tmp);
            }

            tmp.push_back(S[sSize - 1]);
            VecResult.push_back(tmp);
        }

        out:
        return VecResult;
    }
};
