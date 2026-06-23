class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> pref(n), suff(n);

        pref[0] = nums[0];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] | nums[i];

        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            suff[i] = suff[i+1] | nums[i];

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long left = (i ? pref[i-1] : 0);
            long long right = (i+1 < n ? suff[i+1] : 0);

            long long cur =
                left |
                ((long long)nums[i] << k) |
                right;

            ans = max(ans, cur);
        }

        return ans;
    }
};