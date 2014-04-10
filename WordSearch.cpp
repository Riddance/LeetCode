class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {

        if (word.size() == 0) {
            return true;
        }

        int r = 0;
        int c = 0;

        r = board.size();
        if (r) {
            c = board[0].size();
        }

        std::stack<std::pair<int, int> > walkStk;
        std::map<std::pair<int, int>, bool> isVisited;

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {

                int i = 0;

                walkStk.push(std::make_pair(x, y));
                isVisited.clear();

                while (i <= (int)word.size() - 1) {
                    if (walkStk.empty()) {
                        break;
                    }

                    int posX = (walkStk.top()).first;
                    int posY = (walkStk.top()).second;
                    walkStk.pop();

                    isVisited[std::make_pair(posX, posY)] = true;

                    if (word[i] != board[posX][posY]) {
                        continue;
                    }

                    ++i;

                    if (posX - 1 >= 0 && (isVisited.find(std::make_pair(posX - 1, posY)) == isVisited.end()|| isVisited[std::make_pair(posX - 1, posY)] == false)) {
                        walkStk.push(std::make_pair(posX - 1, posY));
                    }

                    if (posX + 1 < r && (isVisited.find(std::make_pair(posX + 1, posY)) == isVisited.end()|| isVisited[std::make_pair(posX + 1, posY)] == false)) {
                        walkStk.push(std::make_pair(posX + 1, posY));
                    }

                    if (posY - 1 >= 0 && (isVisited.find(std::make_pair(posX, posY - 1)) == isVisited.end()|| isVisited[std::make_pair(posX, posY - 1)] == false)) {
                        walkStk.push(std::make_pair(posX, posY - 1));
                    }

                    if (posY + 1 < c && (isVisited.find(std::make_pair(posX, posY + 1)) == isVisited.end() || isVisited[std::make_pair(posX, posY + 1)] == false)) {
                        walkStk.push(std::make_pair(posX, posY + 1));
                    }

                }

                if (i == word.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};
