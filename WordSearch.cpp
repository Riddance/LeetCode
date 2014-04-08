class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
    	if (board.size() == 0 || word.size() == 0) {
    		return false;
    	}

    	if (board.size() != board[0].size()) {
    		return false;
    	}

    	int n = board.size();

    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {

    			if (board[i][j] != word[0])
    				continue;

    			
    		}
    	}

    	return false;
    }
};
