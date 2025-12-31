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
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        vector<int> ans;
        for (auto &e : edges) {
            if (find(e[0]) == find(e[1]))
                ans = e;
            else
                unite(e[0], e[1]);
        }
        return ans;
    }
};
