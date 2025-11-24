class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int an =0;
        for(int i =0;i<nums.size();i++){
            an = 2*an+nums[i];
            ans.push_back(an%5==0);
            an=an%10;
        }
        return ans;
        
    }
};