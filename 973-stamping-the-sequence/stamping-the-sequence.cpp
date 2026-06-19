class Solution {
public:
    bool canStamp(string& target, string& stamp, int pos) {
        bool changed = false;

        for (int i = 0; i < stamp.size(); i++) {
            if (target[pos + i] == '?')
                continue;

            if (target[pos + i] != stamp[i])
                return false;

            changed = true;
        }

        return changed;
    }

    int doStamp(string& target, int pos, int m) {
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            if (target[pos + i] != '?') {
                target[pos + i] = '?';
                cnt++;
            }
        }

        return cnt;
    }

    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();

        vector<int> ans;
        int stars = 0;

        while (stars < n) {
            bool found = false;

            for (int i = 0; i <= n - m; i++) {

                if (canStamp(target, stamp, i)) {

                    int gained = doStamp(target, i, m);

                    if (gained > 0) {
                        found = true;
                        stars += gained;
                        ans.push_back(i);

                        if (stars == n)
                            break;
                    }
                }
            }

            if (!found)
                return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};