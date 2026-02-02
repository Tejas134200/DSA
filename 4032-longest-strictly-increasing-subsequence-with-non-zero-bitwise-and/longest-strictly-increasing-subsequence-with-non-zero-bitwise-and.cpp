class Solution {
public:

    int LIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i < n; i++) {
            if(nums[i] > temp.back()) 
                temp.push_back(nums[i]); 
                
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -temp.begin();
                temp[ind] = nums[i];
            }        
        }
        return temp.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<31;i++){
            vector<int> temp;
            for(int num:nums){
                if(num&(1<<i)) temp.push_back(num);
            }
            mp[i]=temp;
        }
        for(auto it:mp){
            ans = max(ans , LIS(it.second));
        }
        return ans;
    }
};