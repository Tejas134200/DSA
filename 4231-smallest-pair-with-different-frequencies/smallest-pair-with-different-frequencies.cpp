class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(nums[i]!=nums[j]&&(m[nums[i]]!=m[nums[j]])) return {nums[i],nums[j]};
            }
        }
        return {-1,-1};
    }
};