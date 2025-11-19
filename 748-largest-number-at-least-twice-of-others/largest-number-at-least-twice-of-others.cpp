class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> k = nums;
        sort(k.begin(),k.end());
        if(k[k.size()-1]<2*k[k.size()-2]) return -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k[k.size()-1]) return i;
        }
        return 0;
    }
};