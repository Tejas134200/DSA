class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n,0);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1];
            if(nums[i]%2==nums[i-1]%2) pre[i]++;
        }
        n = queries.size();
        vector<bool> ans;
        for(auto& v:queries){
            int l = v[0];
            int r = v[1];
            if(pre[r]==pre[l]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

        
    }
};