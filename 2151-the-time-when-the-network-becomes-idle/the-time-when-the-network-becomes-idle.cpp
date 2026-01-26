class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) { 
        int n = patience.size();
        vector<vector<int>> adj(n);
        for(auto& v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        int c =0;
        q.push(0);
        while(!q.empty()){
            int k=q.size();
            c++;
            while(k--){
                int node = q.front();
                q.pop();
                dist[node]=c-1;
                for(auto it:adj[node]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
        for(int& i:dist) i=i*2;

        for(int i:dist) cout<<i<<" ";
        for(int i =1;i<n;i++){
            patience[i] = ((dist[i]-1)/patience[i])*patience[i];
        }
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxi = max(maxi , patience[i]+dist[i]);
        }
        return maxi+1;
        return 0;
        
    }
};