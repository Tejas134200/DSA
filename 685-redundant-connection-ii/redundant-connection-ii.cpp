class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> indegreeParent(n + 1, 0);

        vector<int> cand1, cand2;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (indegreeParent[v] == 0) {
                indegreeParent[v] = u;
            } else {
                cand1 = {indegreeParent[v], v};
                cand2 = e;
                e[1] = 0;          // mark second edge to skip later
            }
        }

        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {

            if (e[1] == 0)       // skipped second parent edge
                continue;

            if (find(e[0]) == find(e[1])) {

                // No node had two parents
                if (cand1.empty())
                    return e;

                // Cycle still exists after skipping cand2
                return cand1;
            }

            unite(e[0], e[1]);
        }

        // No cycle after removing cand2
        return cand2;
    }
};