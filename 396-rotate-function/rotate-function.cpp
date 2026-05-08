class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        if(n==1) return 0;
        vector<int> pre(n,0) , suf(n,0);
        int sum =0;
        for(int i:nums) sum+=i;
        int ts = 0;
        for(int i =0;i<n;i++){
            suf[i]= sum-ts;
            ts+=nums[i];
            pre[i]=ts;

        }
        int ans = 0;
        for(int i =0;i<n;i++) ans+=(i*nums[i]);
        int prev = ans + pre[n-2] -(n-1)*nums[n-1];
        maxi = max(prev , ans);
        for(int i = n-2;i>0;i--){
            int prev2 = prev+pre[i-1]+suf[i+1]-(n-1)*nums[i];
            maxi = max(prev2 , maxi);
            prev = prev2;
        }
        return maxi;


    }
};