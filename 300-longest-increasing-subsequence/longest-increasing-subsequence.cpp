class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> a;
        a.push_back(nums[0]);
        int in = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>a[in]){
                a.push_back(nums[i]);
                in++;
            }else{
                int k = lower_bound(a.begin(),a.end(),nums[i])-a.begin();
                a[k]=nums[i];
            }
        }
        return a.size();
    }
};