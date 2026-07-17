class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> toBusId;
        int n = routes.size();

        vector<int> busIdVis(n,0);
        unordered_map<int,int> stopVis;

        for(int i =0;i<n;i++){
            for(auto s:routes[i]){
                toBusId[s].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);
        stopVis[source] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int cur = q.front();
                q.pop();
                if(cur==target) return ans;

                for(int e : toBusId[cur]){
                    if(busIdVis[e]==1) continue;
                    busIdVis[e]=1;
                    for(int s:routes[e]){
                        if(stopVis[s]==0){
                            stopVis[s]=1;
                            q.push(s);
                        }
                    }
                }
            }
            ans++;
        }

        return -1;

    }
};