class Solution {
public:
    vector<int>par , rank;
    int find(int x){
        if(par[x]!=x) par[x]=find(par[x]);
        return par[x];
    }
    void unite(int x , int y){
        int px =find(x);int py= find(y);
        if(px==py) return;
        if(rank[px]<rank[py]){
            par[px]=py;

        }else if(rank[py]<rank[px]){
            par[py]=px;
        }else{
            par[px]=py;
            rank[py]++;
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++) par[i]=i;
        for(auto v:edges){
            int x = find(v[0]);
            int y = find(v[1]);
            if(x!=y) unite(x,y);
        }
        unordered_map<int,vector<int>> m;
        for(int i =0;i<n;i++){
            m[find(i)].push_back(i);
        }
        long long ans =0;
        for(auto it:m){
            int ne = it.second.size();
            ans+=((long long)ne*(n-ne));
        }
        return ans/2;
    }
};