class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> des(n, 0);
        for(int i = 1; i < n; i++) {
            if(nums[i-1] >= nums[i])
                des[i] = des[i-1] + 1;
        }

        vector<int> asc(n, 0);
        for(int i = n-2; i >= 0; i--) {
            if(nums[i+1] >= nums[i])
                asc[i] = asc[i+1] + 1;
        }

        vector<int> ans;

        for(int i = k; i < n-k; i++) {
            if(des[i-1] >= k-1 && asc[i+1] >= k-1)
                ans.push_back(i);
        }

        return ans;
    }
};