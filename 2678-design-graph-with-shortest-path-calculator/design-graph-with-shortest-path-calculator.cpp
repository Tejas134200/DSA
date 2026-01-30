class Graph {
public:
    vector<vector<long long>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n,vector<long long>(n,INT_MAX));
        for(int i =0;i<n;i++) adj[i][i]=0;
        for(auto v:edges){
            adj[v[0]][v[1]]=v[2];
        }
        for(int k = 0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u][v] = w;
        for(int k = 0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2]==INT_MAX?-1:adj[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */