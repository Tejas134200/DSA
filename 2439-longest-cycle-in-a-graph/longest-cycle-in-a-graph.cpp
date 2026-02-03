class Solution {
public:
    int ans = -1;

    void dfs(int in,
             unordered_map<int,int>& mp,
             vector<int>& edges,
             vector<int>& vis) {

        vis[in] = 1;
        int neigh = edges[in];

        if (neigh == -1) return;

        // already processed globally → stop
        if (vis[neigh] && mp.find(neigh) == mp.end()) return;

        // new node in current path
        if (mp.find(neigh) == mp.end()) {
            mp[neigh] = mp[in] + 1;
            dfs(neigh, mp, edges, vis);
        }
        // cycle detected
        else {
            ans = max(ans, mp[in] - mp[neigh] + 1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int,int> mp;
                mp.reserve(64);            // small but important
                mp[i] = 1;
                dfs(i, mp, edges, vis);
            }
        }
        return ans;
    }
};
