class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool doUnion(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;

        if(rank[x] < rank[y]) parent[x] = y;
        else if(rank[x] > rank[y]) parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
        return true;
    }

    int kruskal(int n, vector<vector<int>>& edges, int skipEdge, int forceEdge) {
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        int cost = 0;
        int cnt = 0;

        // Force edge
        if(forceEdge != -1) {
            auto &e = edges[forceEdge];
            if(doUnion(e[0], e[1])) {
                cost += e[2];
                cnt++;
            }
        }

        for(int i = 0; i < edges.size(); i++) {
            if(i == skipEdge) continue;
            if(i == forceEdge) continue;

            auto &e = edges[i];
            if(doUnion(e[0], e[1])) {
                cost += e[2];
                cnt++;
                if(cnt == n - 1) break;
            }
        }

        if(cnt != n - 1) return 1e9; // disconnected
        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        for(int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        int base = kruskal(n, edges, -1, -1);

        vector<vector<int>> ans(2);

        for(int i = 0; i < edges.size(); i++) {

            if(kruskal(n, edges, i, -1) > base) {
                ans[0].push_back(edges[i][3]);
            }
            else if(kruskal(n, edges, -1, i) == base) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }
};
