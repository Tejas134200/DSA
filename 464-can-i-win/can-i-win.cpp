class Solution {
public:
    int n, target;
    vector<int> dp;

    bool dfs(int mask, int remaining) {
        if (remaining <= 0)
            return false;

        if (dp[mask] != -1)
            return dp[mask];

        // Try every unused number
        for (int i = 1; i <= n; i++) {

            // If number i is unused
            if (!(mask & (1 << (i - 1)))) {

                // Choose i.
                // If opponent cannot win afterwards,
                // then current player wins.
                if (!dfs(mask | (1 << (i - 1)), remaining - i))
                    return dp[mask] = true;
            }
        }

        // No winning move exists
        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        n = maxChoosableInteger;
        target = desiredTotal;

        if (n * (n + 1) / 2 < target)
            return false;

        if (target <= 0)
            return true;

        dp.assign(1 << n, -1);

        return dfs(0, target);
    }
};