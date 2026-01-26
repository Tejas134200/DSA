class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int rem = n-4;
        for(int i =0 ; i+rem<n;i++){
            mini = min(mini , nums[i+rem]-nums[i]);
        }
        return mini;
    }
};