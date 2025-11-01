class Solution {
public:
    bool backtrack(int start, int k, int subsetSum, int target,
                   vector<int>& nums, vector<bool>& used) {

        if(k == 0) return true;                      
        if(subsetSum == target)                      
            return backtrack(0, k - 1, 0, target, nums, used);

        for(int j = start; j < nums.size(); j++){
            if(used[j]) continue;
            if(subsetSum + nums[j] > target) continue;

            used[j] = true;
            if(backtrack(j + 1, k, subsetSum + nums[j], target, nums, used))
                return true;
            used[j] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int x: nums) sum += x;
        if(sum % k != 0) return false;

        int target = sum / k;

        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] > target) return false;

        vector<bool> used(nums.size(), false);
        return backtrack(0, k, 0, target, nums, used);
    }
};
