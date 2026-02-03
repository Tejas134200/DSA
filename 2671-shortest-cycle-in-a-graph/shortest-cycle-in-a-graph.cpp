class Solution {
public:
    int ans;

    void dfs(int in,
             unordered_map<int,int>& mp,
             vector<vector<int>>& adj,
             vector<int>& vis,
             int par) {

        vis[in] = 1;

        for (int neigh : adj[in]) {
            if (neigh == par) continue;

            if (mp.find(neigh) == mp.end()) {
                mp[neigh] = mp[in] + 1;
                dfs(neigh, mp, adj, vis, in);
            }
            else {
                // correct formula
                ans = min(ans, mp[in] - mp[neigh] + 1);
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        ans = INT_MAX;
        vector<vector<int>> adj(n);

        for (auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        for(int s =0;s<n;s++){
            vector<int> dist(n,-1);
            queue<int> q;
            q.push(s);
            dist[s]=0;
            while(!q.empty()){
                int u = q.front();q.pop();
                for(int v:adj[u]){
                    if(dist[v]==-1){
                        dist[v]=dist[u]+1;
                        q.push(v);
                    }
                    else if(dist[v]>=dist[u]){
                    ans = min(ans , dist[u]+dist[v]+1);
                    }
                }
                
            }
        }


        return ans==INT_MAX?-1:ans;

        
    }
};
