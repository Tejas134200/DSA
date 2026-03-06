class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans =0;
        int n = nums.size();
        vector<int> a(n , 0);
        unordered_map<int , int> m;
        int s=0;
        m[0]++;
        for(int i =0;i<n;i++){
            s+=nums[i];
            int r = s%k;
            if(r<0) r+=k;
            ans+=m[r];
            m[r]++;

        }
        return ans;
    }
};