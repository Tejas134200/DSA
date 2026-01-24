class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int i =0;
        int j = n-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            maxi = max(maxi , nums[i++]+nums[j--]);
        }
        return maxi;
    }
};