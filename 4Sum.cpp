class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	std::vector<std::vector<int> > rv;

    	if ((int)num.size() < 4) {
    		return rv;
    	}

    	struct ValPair{
    		int index1;
    		int index2;
    	};

    	std::multimap<int, ValPair, std::less<int> > SumToPair;
    	for (int i = 0; i < (int)num.size() - 1; ++i) {
    		for (int j = i + 1; j < (int)num.size(); ++j) {

    			ValPair ijPair;
    			ijPair.index1 = i;
    			ijPair.index2 = j;
    			int ijSum = num[i] + num[j];

    			SumToPair.insert(make_pair(ijSum, ijPair));
    		}
    	}

    	assert(SumToPair.size() > 2);

    	using SUM_TO_PAIR_ITER = decltype(SumToPair.begin());
    	std::vector<SUM_TO_PAIR_ITER> VecIter;

    	auto Iter = SumToPair.begin();

    	while (Iter != SumToPair.end()) {
    		VecIter.push_back(Iter);
    		++Iter;
    	}

    	std::vector<int> r(4, 0);

    	for (int i = 0; i < (int)VecIter.size() - 1; ++i) {
    		for (int j = i + 1; j < (int)VecIter.size(); ++j) {
    			auto lhs = VecIter[i];
    			auto rhs = VecIter[j];

    			if (
    				lhs->second.index1 == rhs->second.index1 || 
	    			lhs->second.index1 == rhs->second.index2 ||
	    			lhs->second.index2 == rhs->second.index1 ||
	    			lhs->second.index2 == rhs->second.index2
    			) {
    				continue;
    			}

    			int sumPairs = lhs->first + rhs->first;

    			if (sumPairs != target) {
    				continue;
    			}


    			r[0] = num[lhs->second.index1];
    			r[1] = num[lhs->second.index2];
    			r[2] = num[rhs->second.index1];
    			r[3] = num[rhs->second.index2];

				std::sort(r.begin(), r.end(), std::less<int>());

				if (std::find(rv.begin(), rv.end(), r) == rv.end()) {
					rv.push_back(r);
                }
    		}
    	}

    	return rv;
    }
};