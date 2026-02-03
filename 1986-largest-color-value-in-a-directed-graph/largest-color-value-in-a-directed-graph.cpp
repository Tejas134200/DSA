class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> dp;
    vector<int> state; // 0 = unvisited, 1 = visiting, 2 = done
    string colors;
    int maxi = 0;

    bool dfsCycle(int u) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) return true;
            if (state[v] == 0 && dfsCycle(v)) return true;
        }
        state[u] = 2;
        return false;
    }

    void dfs1(int u) {
        if (dp[u][0] != -1) return;

        for (int j = 0; j < 26; j++) dp[u][j] = 0;

        for (int v : adj[u]) {
            dfs1(v);
            for (int c = 0; c < 26; c++) {
                dp[u][c] = max(dp[u][c], dp[v][c]);
            }
        }

        dp[u][colors[u] - 'a']++;
        for (int c = 0; c < 26; c++) {
            maxi = max(maxi, dp[u][c]);
        }
    }

    int largestPathValue(string colors_, vector<vector<int>>& edges) {
        colors = colors_;
        n = colors.size();
        adj.resize(n);
        for (auto &e : edges) adj[e[0]].push_back(e[1]);

        state.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (state[i] == 0 && dfsCycle(i)) return -1;
        }

        dp.assign(n, vector<int>(26, -1));
        for (int i = 0; i < n; i++) {
            if (dp[i][0] == -1) dfs1(i);
        }

        return maxi;
    }
};
