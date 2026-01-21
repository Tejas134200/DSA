class Solution {
public:
    vector<int> par , rank;
    int find(int x){
        if(par[x]!=x) par[x]=find(par[x]);
        return par[x];
    }

 void unite(int x , int y){
    int px = find(x);
    int py = find(y);
    if(px==py) return;

    if(rank[px]<rank[py]){
        par[px]=py;
    }else if(rank[px]>rank[py]){
        par[py]=px;
    }
    else {
        par[py]=px;
        rank[px]++;
    }
 }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
        for(int i =0;i<n;i++) par[i]=i;
        rank.resize(n,0);

        unordered_map<int,int> row  , col;

        for(int i =0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1];

            if(row.count(r)) unite(i,row[r]);
            else row[r]=i;
            if(col.count(c)) unite(i,col[c]);
            else col[c]=i;


        }
        unordered_set<int> com;
        for(int i =0;i<n;i++) com.insert(find(i));

        return n-com.size();
    
    }
};