class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        long long mod = 1e9+7;
        sort(nums.begin(),nums.end());
        long long ans = (((long long)nums[0]*(long long)nums[0])%mod*(long long)nums[0])%mod;
        long long sum = 0;
        
        for(int i =1;i<n;i++){
            long long maxi = ((long long)nums[i]*(long long)nums[i])%mod;
            sum =( 2*sum+(long long)nums[i-1])%mod;
            ans += (maxi*(sum+(long long)nums[i]))%mod;
            ans%=mod;
        }
        return ans;
    }
};