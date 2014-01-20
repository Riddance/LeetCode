class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>::iterator lhs;
        vector<string>::iterator rhs;
        vector<string> lines;
        int cur = 0;

        if (words.size() == 0) {
            lines.push_back(string(' ', L));
            goto out;
        }

        lhs = rhs = words.begin(); 
        while (rhs != words.end()) {
            if (cur + rhs->size() <= L) {
                cur += rhs->size() + 1;
                ++rhs;
                if (rhs != words.end()) {
                    continue;
                }
            }

            int cnt = distance(lhs, rhs - 1) + 1;
            string line;
            if (cnt == 1) {
                line += *lhs + string(L - lhs->size(), ' ');
            }
            else if (cnt > 1 && rhs == words.end())
            {
                int e = 1;
                int m = L - cur;

                for (; lhs != (rhs - 1); ++lhs) {
                    line += *lhs + string(e, ' ');
                }

                line += *lhs + string(m, ' ');
            }
            else {
                int e = (L - cur + cnt) / (cnt - 1);
                int m = (L - cur + cnt) % (cnt - 1);

                for (; lhs != (rhs - 1); ++lhs) {
                    if (m != 0) {
                        line += *lhs + string(e + 1, ' ');
                        --m;
                    }
                    else
                    {
                        line += *lhs + string(e, ' ');
                    }
                }
                line += *lhs;
            }

            lines.push_back(line);
            lhs = rhs;
            cur = 0;
        }
        
    out:
        return lines;
    }
};