class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        for (int i = 1; i < (int)s1.size(); ++i) {
            string s1_l = s1.substr(0, i);
            string s2_l = s2.substr(0, i);
            std::sort(s1_l.begin(), s1_l.end());
            std::sort(s2_l.begin(), s2_l.end());

            if (s1_l == s2_l) {

                if (
                    isScramble(s1.substr(0, i), s2.substr(0, i)) 
                    && isScramble(s1.substr(i), s2.substr(i))
                    ) {
                        return true;
                }

            }

            string s2_r = s2.substr(s2.size() - i, i);
            std::sort(s2_r.begin(), s2_r.end());

            if (s1_l == s2_r) {
                if (
                    isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i))
                    && isScramble(s1.substr(i), s2.substr(0, s2.size() - i))
                    ) {
                        return true;
                }
                
            }
        }

        return false;
    }
};