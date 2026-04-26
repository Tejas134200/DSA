class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum = 0;
        for(int i:nums) sum+=i;

        long long ss = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) ss+=nums[i];
            else {
                long long st = sum-ss+nums[i-1];
                if(ss==st) return -1;
                return ss<st;
            }
        }
        return 0;

    }
};