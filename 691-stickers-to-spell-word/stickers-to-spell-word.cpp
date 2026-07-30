class Solution {
public:
    unordered_map<string,int> dp;
    int solve(vector<vector<int>>& cnt , string target){
        if(target.empty()) return 0;
        if(dp.count(target)) return dp[target];


        vector<int> need(26, 0);
        for (char c : target)
            need[c - 'a']++;

        int ans = INT_MAX;

        for(auto& sticker:cnt){
            if (sticker[target[0] - 'a'] == 0)
                continue;

            string rem = "";

            // Build remaining string after using this sticker
            for (int i = 0; i < 26; i++) {
                int left = max(0, need[i] - sticker[i]);
                rem += string(left, 'a' + i);
            }
            int sub = solve(cnt, rem);

            if (sub != -1)
                ans = min(ans, 1 + sub);
        }
        dp[target]=ans==INT_MAX?-1:ans;
        return dp[target];

    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> cnt;
        for (string &s : stickers) {
            vector<int> f(26, 0);
            for (char c : s)
                f[c - 'a']++;
            cnt.push_back(f);
        }
        return solve(cnt, target);
    }
};