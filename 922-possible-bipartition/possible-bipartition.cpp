class Solution {
public:
    vector<int> par, rank;

    int find(int x) {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) par[px] = py;
        else if (rank[px] > rank[py]) par[py] = px;
        else {
            par[py] = px;
            rank[px]++;
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        par.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            par[i] = i;
        vector<vector<int>> adj(n+1 , vector<int>());
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i =1;i<=n;i++){
            if(adj[i].empty()) continue;
            int first = adj[i][0];
            for(int j=1;j<adj[i].size();j++){
                unite(first ,adj[i][j]);
                if(find(i)==find(adj[i][j])){
                    return false;
                }
            }
        }

        return true;

    }
};