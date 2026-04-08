class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9+7;
        for(auto &q:queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for(int i = l;i<=r;i+=k){
                nums[i]= ((long long)nums[i]*v)%mod;
            }
        }
        int xo = 0;
        for(int i:nums) xo^=i;
        return xo;
    }
};