//will time of limit
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        struct StrPos {
            int pos_s1;
            int pos_s2;
            int pos_s3;
            StrPos(int ps1 = 0, int ps2 = 0, int ps3 = 0):pos_s1(ps1), pos_s2(ps2), pos_s3(ps3) {
            }
        };

        std::stack<StrPos> pos_stack;
        StrPos cur_pos;

        while (cur_pos.pos_s3 <= (int)s3.size() - 1) {

            if (cur_pos.pos_s1 > (int)s1.size() - 1)
                return string(s2, cur_pos.pos_s2, s2.size() - cur_pos.pos_s2) == string(s3, cur_pos.pos_s3, s3.size() - cur_pos.pos_s3);

            if (cur_pos.pos_s2 > (int)s2.size() - 1)
                return string(s1, cur_pos.pos_s1, s1.size() - cur_pos.pos_s1) == string(s3, cur_pos.pos_s3, s3.size() - cur_pos.pos_s3);

            if (s1[cur_pos.pos_s1] == s2[cur_pos.pos_s2] && s2[cur_pos.pos_s2] == s3[cur_pos.pos_s3]) {
                pos_stack.push(StrPos(cur_pos.pos_s1, cur_pos.pos_s2 + 1, cur_pos.pos_s3 + 1));
                cur_pos = StrPos(cur_pos.pos_s1 + 1, cur_pos.pos_s2, cur_pos.pos_s3 + 1);
            }
            else if (s1[cur_pos.pos_s1] == s3[cur_pos.pos_s3]) {
                cur_pos = StrPos(cur_pos.pos_s1 + 1, cur_pos.pos_s2, cur_pos.pos_s3 + 1);
            }
            else if (s2[cur_pos.pos_s2] == s3[cur_pos.pos_s3]) {
                cur_pos = StrPos(cur_pos.pos_s1, cur_pos.pos_s2 + 1, cur_pos.pos_s3 + 1);
            }
            else {
                if (!pos_stack.empty()) {
                    cur_pos = pos_stack.top();
                    pos_stack.pop();
                }
                else {
                    break;
                }
            }
        }

        if (cur_pos.pos_s3 == s3.size())
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_size = (int)s1.size();
        int s2_size = (int)s2.size();
        int s3_size = (int)s3.size();

        if (s1_size + s2_size != s3_size)
            return false;

        bool* pres = new bool[(s1_size + 1) * (s2_size + 1)];
        memset(pres, 0, sizeof(bool) * (s1_size + 1) * (s2_size + 1));
        assert(pres);
        bool result = false;

        pres[0] = true;

        for (int i = 1; i <= s1_size; ++i) {
            pres[(s2_size + 1)* i] = string(s1, 0, i) == string(s3, 0, i);
        }

        for (int i = 1; i <= s2_size; ++i) {
            pres[i] = string(s2, 0, i) == string(s3, 0, i);
        }

        for (int i = 1; i <= s1_size; ++i) {
            for (int j = 1; j <= s2_size; ++j) {
                pres[i * (s2_size + 1) + j] = (s2[j - 1] == s3[i + j - 1] && pres[i * (s2_size + 1) + j - 1]) || (s1[i - 1] == s3[i + j - 1] && pres[(i - 1) * (s2_size + 1) + j]);
            }
        }


        result = pres[(s1_size + 1) * (s2_size + 1) - 1];
        if (pres) {
            free(pres);
            pres = NULL;
        }

        return result;
    }
};