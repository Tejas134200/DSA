class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adj;
    int minCostConnectPoints(vector<vector<int>>& points) {
         n = points.size();
         adj.resize(n,vector<pair<int,int>>());
         for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});

            }
         }

        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        vector<int> vis(n,0);
        int ans =0;
        int nv =0;
        pq.push({0,0});
        while(nv<n){
            auto it = pq.top();

            pq.pop();
            if(vis[it.second]==1) continue;
            ans+=it.first;
            nv++;
            vis[it.second]=1;
            for(auto i:adj[it.second]){
                if(vis[i.second]==0){
                    pq.push({i.first , i.second});
                }
            }

        }
        return ans;
        
        

    }
};