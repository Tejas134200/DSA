class Solution {
public:
   bool isn(int a, int b, int c) {
    long long x = 1LL * a * a;
    long long y = 1LL * b * b;
    long long z = 1LL * c * c;

    return (x + y == z) || (x + z == y) || (y + z == x);
}


    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<int> a(n),b(n),c(n);
        a[x]=0;
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(x);
        vis[x]=1;
        
        int count =0;
        while(!q.empty()){
            int kk = q.size();
            while(kk--){
                int node= q.front();
                q.pop();
                a[node]=count;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            count++;
        }
        fill(vis.begin(), vis.end(), 0);
        while(!q.empty()) q.pop();
        q.push(y);
        vis[y]=1;
        count =0;
        while(!q.empty()){
            int kk = q.size();
            while(kk--){
                int node= q.front();
                q.pop();
                b[node]=count;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            count++;
        }
fill(vis.begin(), vis.end(), 0);   while(!q.empty()) q.pop();     q.push(z);
        vis[z]=1;
        count =0;
        while(!q.empty()){
            int kk = q.size();
            while(kk--){
                int node= q.front();
                q.pop();
                c[node]=count;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            count++;
        }

        int ans=0;
        for(int i =0;i<n;i++){
            if(isn(a[i],b[i],c[i])) ans++;
        }
        return ans;
        
        
    }
};