class Solution {
public:
    bool dfs(
        string cur,
        string target,
        map<string, vector<pair<string, double>>>& adj,
        map<string, bool>& vis,
        double &res
    ) {
        if (cur == target) return true;

        vis[cur] = true;

        for (auto &p : adj[cur]) {
            string next = p.first;
            double val = p.second;

            if (!vis[next]) {
                double prev = res;
                res *= val;
                if (dfs(next, target, adj, vis, res))
                    return true;
                res = prev;
            }
        }
        return false;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < values.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string a = q[0], b = q[1];

            if (!adj.count(a) || !adj.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            map<string, bool> vis;
            double res = 1.0;

            if (dfs(a, b, adj, vis, res))
                ans.push_back(res);
            else
                ans.push_back(-1.0);
        }

        return ans;
    }
};
