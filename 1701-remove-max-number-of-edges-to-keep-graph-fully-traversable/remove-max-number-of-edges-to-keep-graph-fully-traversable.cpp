class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        int components;

        DSU(int n) {
            parent.resize(n + 1);
            rank.assign(n + 1, 0);
            components = n;
            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;

            components--;
            return true;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU alice(n), bob(n);

        int removed = 0;

        // Process common edges first
        for (auto &e : edges) {
            if (e[0] == 3) {
                bool used = alice.unite(e[1], e[2]);
                bob.unite(e[1], e[2]);

                if (!used)
                    removed++;
            }
        }

        // Alice only
        for (auto &e : edges) {
            if (e[0] == 1) {
                if (!alice.unite(e[1], e[2]))
                    removed++;
            }
        }

        // Bob only
        for (auto &e : edges) {
            if (e[0] == 2) {
                if (!bob.unite(e[1], e[2]))
                    removed++;
            }
        }

        if (alice.components != 1 || bob.components != 1)
            return -1;

        return removed;
    }
};