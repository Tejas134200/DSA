class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        for(int i =1;i<n;i++){
            int maxi =INT_MIN;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxi =max(maxi , dp[j]);
                }
            }
            if(maxi==INT_MIN) continue;
            dp[i]=maxi+1;
            int c = 0;
            for(int j =0;j<i;j++){
                if(nums[j]<nums[i]&&dp[j]==maxi) c+=(cnt[j]);
            }
            cnt[i]=c;
        }
        int ans=0;
        int maxi=0;
        for(int i =0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ans=0;
                ans+=cnt[i];
            }
            else if(dp[i]==maxi) ans+=cnt[i];
        }
        return ans;

    }
};