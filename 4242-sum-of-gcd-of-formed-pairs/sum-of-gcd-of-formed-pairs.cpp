class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi =-1;
        for(int i =0;i<n;i++){
            maxi = max(maxi , nums[i]);
            nums[i] = __gcd(maxi, nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long sum =0;
        for(int i=0;i<n/2;i++){
            sum+=__gcd(nums[i], nums[n-i-1]);
        }
        return sum;
        
    }
};