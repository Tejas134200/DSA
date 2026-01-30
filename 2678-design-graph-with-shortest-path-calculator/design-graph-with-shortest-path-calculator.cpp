class Graph {
public:
    vector<vector<long long>> adj;
    int n;
    const long long INF = 1e18;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.assign(n, vector<long long>(n, INF));

        for(int i = 0; i < n; i++) adj[i][i] = 0;

        for(auto &v : edges){
            int u = v[0], w = v[2], to = v[1];
            adj[u][to] = min(adj[u][to], (long long)w);
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(adj[i][k] == INF) continue;
                for(int j = 0; j < n; j++){
                    if(adj[k][j] == INF) continue;
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];

        if(w >= adj[u][v]) return;
        adj[u][v] = w;

        for(int i = 0; i < n; i++){
            if(adj[i][u] == INF) continue;
            for(int j = 0; j < n; j++){
                if(adj[v][j] == INF) continue;
                adj[i][j] = min(adj[i][j], adj[i][u] + w + adj[v][j]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == INF ? -1 : (int)adj[node1][node2];
    }
};
