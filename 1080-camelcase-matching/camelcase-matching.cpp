class Solution {
public:
    bool solve(const string &query, const string &pattern) {
        int i = 0, j = 0;
        while (i < query.size()) {
            char ch = query[i];
            if (j < pattern.size() && ch == pattern[j]) {
                i++;
                j++;
            } else if (islower(ch))
                i++;
            else
                return false;
        }
        return j == pattern.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++)
            ans[i] = solve(queries[i], pattern);
        return ans;
    }
};