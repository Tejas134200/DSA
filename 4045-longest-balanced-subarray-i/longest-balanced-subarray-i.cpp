class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n =nums.size();
        int ans =0;
        int ce =0;
        int co =0;
        for(int i =0;i<n;i++){
            set<int> e;
            set<int> o;
            for(int j =i;j<n;j++){
                if(nums[j]%2==0) e.insert(nums[j]);
                else o.insert(nums[j]);
                if(e.size()==o.size()) ans = max(ans , j-i+1);
            }
        }
        return ans;
    }
};