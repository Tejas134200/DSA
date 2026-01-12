class Solution {
public:

    char backward_rotation(char ch){
        if (ch - '0' > 0) return (ch - 1);
        return '9';
    }

    char forward_rotation(char ch){
        if (ch - '0' < 9) return (ch + 1);
        return '0';
    }

    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> not_allowed(deadends.begin(), deadends.end());

        if (not_allowed.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        not_allowed.insert("0000");

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();

                if (curr == target) return level;

                for (int i = 0; i < 4; i++) {
                    string next = curr;

                    next[i] = forward_rotation(curr[i]);
                    if (!not_allowed.count(next)) {
                        not_allowed.insert(next);
                        q.push(next);
                    }

                    next[i] = backward_rotation(curr[i]);
                    if (!not_allowed.count(next)) {
                        not_allowed.insert(next);
                        q.push(next);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};