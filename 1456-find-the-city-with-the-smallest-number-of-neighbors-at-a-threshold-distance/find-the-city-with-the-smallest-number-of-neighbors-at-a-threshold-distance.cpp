class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,100001));
        for(int i =0;i<n;i++) adj[i][i]=0;
        for(auto v:edges){
            adj[v[0]][v[1]]=v[2];
            adj[v[1]][v[0]]=v[2];
        }
        for(int k = 0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans =0;
        int minn = 1000;
        for(int i =0;i<n;i++){
            int c =0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold) c++;
            }
            if(c<minn){
                minn = c;
                ans = i;
            }
            else if(c==minn){
                ans = max(ans,i);
            }
        }
        return ans;
    }
};