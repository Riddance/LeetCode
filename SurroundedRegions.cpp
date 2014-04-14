class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int r = (int)board.size();
        int c = 0;
        if (r) {
            c = (int)board[0].size();
        }

        if (r == 0 || c == 0) {
            return;
        }

        std::set<std::pair<int, int> >      filterSet;
        std::stack<std::pair<int, int> >    filterStk;

        for (int i = 0; i < c; ++i) {
            if (board[0][i] == 'O') {
                filterStk.push(std::make_pair(0, i));
            }

            if (r - 1 > 0 && board[r - 1][i] == 'O') {
                filterStk.push(std::make_pair(r - 1, i));
            }
        }

        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') {
                filterStk.push(std::make_pair(i, 0));
            }

            if (c - 1 > 0 && board[i][c - 1] == 'O') {
                filterStk.push(std::make_pair(i, c - 1));
            }
        }

        while (!filterStk.empty()) {
            std::pair<int, int> pos = filterStk.top();
            filterStk.pop();

            if (filterSet.find(pos) != filterSet.end()) {
                continue;
            }

            filterSet.insert(pos);

            if (pos.first > 0 && board[pos.first - 1][pos.second] == 'O') {
                filterStk.push(std::make_pair(pos.first - 1, pos.second));
            }

            if (pos.first < r - 1 && board[pos.first + 1][pos.second] == 'O') {
                filterStk.push(std::make_pair(pos.first + 1, pos.second));
            }

            if (pos.second > 0 && board[pos.first][pos.second - 1] == 'O') {
                filterStk.push(std::make_pair(pos.first, pos.second - 1));
            }

            if (pos.second < c - 1 && board[pos.first][pos.second + 1] == 'O') {
                filterStk.push(std::make_pair(pos.first, pos.second + 1));
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'X' || filterSet.find(std::make_pair(i, j)) != filterSet.end()) {
                    continue;
                }

                board[i][j] = 'X';

                if (i > 0 && board[i - 1][j] == 'O') {
                    board[i - 1][j] = 'X';
                }

                if (i < r - 1 && board[i + 1][j] == 'O') {
                    board[i + 1][j] = 'X';
                }

                if (j > 0 && board[i][j - 1] == 'O') {
                    board[i][j - 1] = 'X';
                }

                if (j < c - 1 && board[i][j + 1] == 'O') {
                    board[i][j + 1] = 'X';
                }
            }
        }

        return;
    }
};
