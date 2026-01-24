class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(), s.end());
        int i = 0, c = 0;

        while (i < (int)s.size() - 1) {
            if (s[i] == '0') {
                i++;
                c++;
            } else {
                int j = i;
                while (j < (int)s.size() && s[j] == '1') {
                    s[j] = '0';
                    j++;
                }
                if (j == s.size()) s.push_back('1');
                else s[j] = '1';
                c++;
            }
        }
        return c;
    }
};
