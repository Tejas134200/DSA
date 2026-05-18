class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int& x = nums[i];

            if (mp.count(x - 1)) {
                mp[x - 1]++;
                mp[x]++;
            }

            if (mp.count(x + 1)) {
                mp[x + 1]++;
                mp[x]++;
            }

            mp[x]++;
        }

        for (auto& [num, freq] : mp) {
            if (freq == 1)
                ans.push_back(num);
        }

        return ans;
    }
};