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

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result(1, vector<int>());

        if (S.size() == 0) {
            return result;
        }

        std::sort(S.begin(), S.end(), std::less<int>());

        for (int i = 0; i < (int)S.size(); ++i) {
            int j = (int)result.size();

            while (--j >= 0) {
                result.push_back(result[j]);
                (result.back()).push_back(S[i]);
            }
        }

        return result;
    }
};
