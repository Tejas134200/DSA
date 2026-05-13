class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> num(nums.begin(), nums.end());

        for(int i = 0; i < num.size(); i++) {
            if(s[i] == 'R') num[i] += d;
            else num[i] -= d;
        }

        sort(num.begin(), num.end());

        long long mod = 1e9 + 7;
        long long ans = 0, pref = 0;

        for(long long i = 0; i < num.size(); i++) {
            ans = (ans + i * num[i] - pref) % mod;
            if(ans < 0) ans += mod;
            pref += num[i];
        }

        return ans;
    }
};