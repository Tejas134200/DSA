class Solution {
public:
    int n, k;
    string abc = "abc";
    string ans = "";

    void solve(int i = 0, string th = "", char prev = 'z') {
        if (!ans.empty()) return;

        if (i == n) {
            k--;
            if (k == 0)
                ans = th;
            return;
        }

        for (int ii = 0; ii < 3; ii++) {
            if (abc[ii] != prev) {
                solve(i + 1, th + abc[ii], abc[ii]);
            }
        }
    }

    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;

        solve();

        return ans;
    }
};