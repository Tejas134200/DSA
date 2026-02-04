class Solution {
private:
    using ll = long long;

public:
    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ranges;
        vector<int> changes;

        for (int i = 1; i < n; i++) {
            int val = 0;
            if (nums[i - 1] < nums[i])
                val = 1;
            if (nums[i - 1] > nums[i])
                val = -1;

            if (changes.empty() || changes.back() != val) {
                changes.emplace_back(val);
                ranges.push_back({i - 1, i});
            } else {
                ranges.back().second = i;
            }
        }

        int m = changes.size();
        ll ans = -1e17;

        for (int i = 1; i < m - 1; i++) {
            if (!(changes[i - 1] == 1 && changes[i] == -1 &&
                  changes[i + 1] == 1)) {
                continue;
            }

            ll sum = 0;
            for (int j = ranges[i].first - 1; j <= ranges[i].second + 1; j++) {
                sum += nums[j];
            }

            ll bestBefore = 0, runSum = 0;
            for (int j = ranges[i].first - 2; j >= 0; j--) {
                if (nums[j] >= nums[j + 1]) {
                    break;
                }
                runSum += nums[j];
                bestBefore = max(bestBefore, runSum);
            }

            ll bestAfter = 0;
            runSum = 0;
            for (int j = ranges[i].second + 2; j < n; j++) {
                if (nums[j] <= nums[j-1]) {
                    break;
                }
                runSum += nums[j];
                bestAfter = max(bestAfter, runSum);
            }
            ans = max(ans, bestAfter + sum + bestBefore);
        }

        return ans;
    }
};