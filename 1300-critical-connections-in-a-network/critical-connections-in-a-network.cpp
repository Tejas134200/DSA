class Solution {
public:
    int timer;
    vector<vector<int>> ans;
    vector<int> vis;
    vector<int> low,tin;
    void dfs(int node , int par ,  vector<vector<int>>& adj ){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;

        for(auto& e:adj[node]){
            if(e==par) continue;
            if(vis[e]==0){
                dfs(e , node , adj);
                low[node] = min(low[node],low[e]);
                if(tin[node]<low[e]){
                    ans.push_back({node , e});
                }
            }else{
                low[node] = min(low[node],low[e]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vis.resize(n,0);
        timer = 1;
        low.resize(n);
        tin.resize(n);

        dfs(0,-1,adj);


        return ans;



    }
};