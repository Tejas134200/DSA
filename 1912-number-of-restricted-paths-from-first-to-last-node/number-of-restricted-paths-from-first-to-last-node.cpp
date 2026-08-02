class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist;
    vector<int> dp;

    int dfs(int u, int n) {
        if (u == n) return 1;
        if (dp[u] != -1) return dp[u];

        long long ways = 0;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] < dist[u]) {
                ways = (ways + dfs(v, n)) % MOD;
            }
        }

        return dp[u] = ways;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        adj.resize(n + 1);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Dijkstra from node n
        dist.assign(n + 1, LLONG_MAX);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[n] = 0;
        pq.push({0, n});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        dp.assign(n + 1, -1);
        return dfs(1, n);
    }
};