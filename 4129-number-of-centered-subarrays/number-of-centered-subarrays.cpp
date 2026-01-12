class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            unordered_map<int,int> m;
            int sum =0;
            for(int j =i;j<n;j++){
                sum+=nums[j];
                m[nums[j]]++;
                if(m[sum]!=0) ans++;
                
            }
        }
        return ans;
    }
};