class Solution {
public:

    void dfs(int in , unordered_map<int,int>& mp ,vector<int>& edges,vector<int>& vis){
        vis[in] =1;
        int neigh = edges[in];
        if(neigh==-1) return;
        if(vis[neigh]==0&&mp.find(neigh)==mp.end()){
            mp[neigh] = 1+mp[in];
            dfs(neigh , mp , edges , vis);
        }
        else if(vis[neigh]==1&&mp.count(neigh)){
            int k = mp[in]-mp[neigh]+1;
            ans=max(ans , k);
        }
        return;
    }
    int ans;

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dp(n,-1);
        vector<int> vis(n,0);
        int maxi =-1;
        int c =0;
        ans =-1;
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                unordered_map<int,int> mp;
                mp[i]=1;
                dfs(i,mp,edges,vis);
            }
        }
        return ans;
    }
};