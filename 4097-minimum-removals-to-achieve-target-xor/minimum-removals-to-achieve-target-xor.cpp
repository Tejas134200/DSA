class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> dp;
        dp[0] = 0;
        
        for(int num : nums){
            auto ndp = dp;
            
            for(auto &it : dp){
                int x = it.first;
                int cnt = it.second;
                
                int nx = x ^ num;
                ndp[nx] = max(ndp[nx], cnt + 1);
            }
            
            dp = ndp;
        }
        
        if(dp.find(target) == dp.end()) return -1;
        return n - dp[target];
    }
};