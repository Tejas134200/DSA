class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (ind[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int it : adj[node]) {
                ans[it].insert(node);
                ans[it].insert(ans[node].begin(), ans[node].end());

                if (--ind[it] == 0)
                    q.push(it);
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++)
            res[i] = vector<int>(ans[i].begin(), ans[i].end());

        return res;
    }
};
