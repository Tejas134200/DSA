class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj, vector<vector<int>>& adj2 , vector<int>& vis ){
        vis[node]++;
        for(auto it:adj[node]){
            if(vis[it]==0 && find(adj2[node].begin(),adj2[node].end(),it)!=adj2[node].end()) ans++;
            if(vis[it]==0) dfs(it , adj , adj2 , vis);
        }
    }
    int ans;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto& v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        ans =0;
        vector<vector<int>> adj2(n,vector<int>());
        for(auto& v:connections){
            adj2[v[0]].push_back(v[1]);
        }
        vector<int> vis(n,0);
        dfs(0,adj,adj2,vis);
        return ans;

    }
};