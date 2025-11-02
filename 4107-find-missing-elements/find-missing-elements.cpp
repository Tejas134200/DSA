class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=-1;
        int n = nums.size();
        int mini=1000;
        vector<int> f(101,0);
        vector<int> ans;
        for(int i:nums){
            if(i<mini) mini=i;
            if(i>maxi) maxi=i;
            f[i]++;
        }
        for(int i = mini;i<=maxi;i++){
            if(f[i]==0) ans.push_back(i);
        }
        return ans;
        
        
    }
};