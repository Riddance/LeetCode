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
        std::vector<std::pair<int, int> > matchPos;

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {

                int i = 0;

                walkStk.push(std::make_pair(x, y));
                isVisited.clear();
                matchPos.clear();

                while (i <= (int)word.size() - 1) {
                    if (walkStk.empty()) {
                        break;
                    }

                    int posX = (walkStk.top()).first;
                    int posY = (walkStk.top()).second;
                    walkStk.pop();

                    if (posX == -1 || word[i] != board[posX][posY]) {
                        if (posX == -1) {
                            --i;

                            isVisited[matchPos.back()] = false;
                            matchPos.pop_back();
                        }

                        continue;
                    }

                    matchPos.push_back(std::make_pair(posX, posY));
                    isVisited[std::make_pair(posX, posY)] = true;

                    ++i;

                    walkStk.push(std::make_pair(-1, -1));

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
