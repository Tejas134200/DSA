class Solution {
public:
    vector<int> par,rank;
    int find(int x){
        if(par[x]!=x) par[x] = find(par[x]);
        return par[x];
    }
    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px==py) return;
        if(rank[px]<rank[py]){
            par[px]=py;
        }else if(rank[px]>rank[py]){
            par[py]=px;
        }else{
            par[px]=py;
            rank[py]++;
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++) par[i]=i;
        int c =0;
        
        for(auto& e:connections){
            int u= e[0];
            int v =e[1];
            if(find(u)==find(v)) c++;
            else unite(u,v);
        }
        unordered_set<int> s;
        for(int i =0;i<n;i++) s.insert(find(i));
        int com = s.size();
        int req = com-1;

        if(c>=req) return req;
        return -1;
    }
};