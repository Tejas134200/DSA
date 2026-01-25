class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [p, node] = pq.top();
            pq.pop();

            if (node == end) return p;

            if (p < prob[node]) continue;

            for (auto [nn, w] : adj[node]) {
                if (prob[nn] < p * w) {
                    prob[nn] = p * w;
                    pq.push({prob[nn], nn});
                }
            }
        }

        return 0.0;
    }
};
