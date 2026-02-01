class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i =0;i<1;i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    mini = min(mini , nums[i]+nums[j]+nums[k]);
                }
            }
        }
        return mini;
    }
};