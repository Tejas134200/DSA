class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> dp(n + 1, 0), prev(n + 2, 0);
        dp[0] = 1;
        prev[1] = 1;

        deque<int> minq, maxq;
        int l = 0;

        for (int i = 0; i < n; i++) {
            // \U0001f527 Fix: Use back() for insertion
            while (!minq.empty() && nums[i] < nums[minq.back()]) minq.pop_back();
            while (!maxq.empty() && nums[i] > nums[maxq.back()]) maxq.pop_back();

            minq.push_back(i);
            maxq.push_back(i);

            // shrink window if invalid
            while (nums[maxq.front()] - nums[minq.front()] > k) {
                if (minq.front() == l) minq.pop_front();
                if (maxq.front() == l) maxq.pop_front();
                l++;
            }

            dp[i + 1] = (prev[i + 1] - prev[l] + MOD) % MOD;
            prev[i + 2] = (prev[i + 1] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};