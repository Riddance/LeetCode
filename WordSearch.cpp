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
        
        vector<int> isVisited(r*c, 0);

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {

                memset(&isVisited[0], 0, isVisited.size() * sizeof(int));

                stack<int> walkStk;

                walkStk.push(x*c + y);

                int i = 0;
                while (i <= (int)word.size() - 1) {
                    if (walkStk.empty()) {
                        break;
                    }

                    int posX = (walkStk.top()) / c;
                    int posY = (walkStk.top()) % c;
                    walkStk.pop();

                    isVisited[x*c + y] = 1;

                    if (word[i] != board[posX][posY]) {
                        continue;
                    }

                    ++i;

                    if (posX - 1 >= 0 && isVisited[(posX - 1)*c + posY] == false) {
                        walkStk.push((posX - 1)*c + posY);
                    }

                    if (posX + 1 < r && isVisited[(posX + 1)*c + posY] == false) {
                        walkStk.push((posX + 1)*c + posY);
                    }

                    if (posY - 1 >= 0 && isVisited[posX *c + posY - 1] == false) {
                        walkStk.push(posX *c + posY - 1);
                    }

                    if (posY + 1 < c && isVisited[posX *c + posY + 1] == false) {
                        walkStk.push(posX *c + posY + 1);
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
