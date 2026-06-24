class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        vector<int> cnt(32,0);

        auto getOr = [&]() {
            long long val = 0;

            for(int b=0;b<32;b++) {
                if(cnt[b])
                    val |= (1LL<<b);
            }

            return val;
        };

        int n = nums.size();
        int ans = INT_MAX;
        int l = 0;

        for(int r=0;r<n;r++) {

            for(int b=0;b<32;b++) {
                if(nums[r]&(1<<b))
                    cnt[b]++;
            }

            while(l<=r && getOr()>=k) {

                ans = min(ans,r-l+1);

                for(int b=0;b<32;b++) {
                    if(nums[l]&(1<<b))
                        cnt[b]--;
                }

                l++;
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};