class Solution {
public:

int bfsLevel(int src, vector<vector<int>>& adj, int n){

        vector<int> dist(n + 1, -1);

        queue<int> q;

        q.push(src);

        dist[src] = 1;

        int mx = 1;

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int v : adj[u]){

                if(dist[v] == -1){

                    dist[v] = dist[u] + 1;

                    mx = max(mx, dist[v]);

                    q.push(v);
                }
            }
        }

        return mx;
    }

    bool bipartite(int i , vector<vector<int>>& adj , vector<int>& colors){
        queue<int> q;
        q.push(i);
        colors[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            int col = colors[node];
            int nxc = -col;

            for(auto e:adj[node]){
                if(colors[e]==0){
                    colors[e] = nxc;
                    q.push(e); 
                }else{
                    if(colors[e]!=nxc) return false;
                }
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> colors(n+1 , 0);

        for(int i =1;i<=n;i++){
            if(colors[i]==0){
                if(!bipartite(i,adj,colors)) return -1;
            }
        }

        vector<int> vis(n+1 , 0);

        int ans = 0;
        for(int i =1;i<=n;i++){
            if(vis[i]) continue;

            vector<int> comp;
            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                comp.push_back(u);
                for(int v:adj[u]){
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            int best = 0;
            for(int node:comp) best = max(best , bfsLevel(node , adj , n));

            ans+=best;
        }

        return ans;

    }
};