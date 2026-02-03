class Solution {
public:
    vector<int>BFS(vector<int>& edges, int src){
        int n = edges.size();
        vector<vector<pair<int,int>>>adjlist(n);

        for(int i = 0 ; i < n ; i++){
            adjlist[i].push_back({edges[i],1});
        }

        vector<int>dist(n,1e9);
        queue<pair<int,int>>q;

        q.push({src,0});
        dist[src] = 0;

        while(!q.empty()){
            auto [node, dis] = q.front();
            q.pop();

            for(auto it : adjlist[node]){
                int new_node = it.first;
                int new_dis = it.second;
                if(new_node != -1 && dist[new_node] > new_dis + dis){
                    dist[new_node] = new_dis + dis;
                    q.push({new_node,new_dis+dis});
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dist1 = BFS(edges, node1);
        vector<int>dist2 = BFS(edges, node2);

        int ans = -1;
        int mini = INT_MAX;

        for(int i = 0 ; i< edges.size(); i++){
            if(dist1[i] != 1e9 && dist2[i] != 1e9){
                int maxi = max(dist1[i],dist2[i]);
                if(mini > maxi){
                    mini = maxi;
                    ans = i;
                }
            }
        }
        return ans;
    }
};