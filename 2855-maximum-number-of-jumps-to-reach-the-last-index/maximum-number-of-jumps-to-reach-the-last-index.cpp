class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i =1;i<n;i++){
            int maxi = -1;
            for(int j = 0;j<i;j++){
                if(abs(nums[j]-nums[i])<=target&&dp[j]!=-1){
                    maxi = max(maxi , dp[j]+1);
                }
            }
            dp[i] = maxi;
        }
        return dp[n-1];
    }
};