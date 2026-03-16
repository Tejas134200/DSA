class Solution {
public:

    vector<int> par , rank;

    int find(int x){
        if(par[x]!=x) par[x]=find(par[x]);
        return par[x];
    }

    void unite(int a , int b){
        int aa = find(a);
        int bb = find(b);

        if(aa==bb) return;

        if(rank[aa]<rank[bb]){
            par[aa]=bb;
        
        }else if(rank[bb]<rank[aa]){
            par[bb]=aa;
        }else{
            par[bb]=aa;
            rank[aa]++;
        }
    }
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n);
        for(int i =0;i<n;i++) par[i]=i;
        rank.resize(n,0);

        unordered_map<int,int> row , col;
        for(int i =0;i<n;i++){
            int r = points[i][0];
            int c = points[i][1];

            if(row.count(r)) unite(i , row[r]);
            else row[r]=i;
            if(col.count(c)) unite(i , col[c]);
            else col[c]=i;
        }
        unordered_map<int,int> comp;
        for(int i=0;i<n;i++){
            int parent = find(i);
            comp[parent]++;
        }
        vector<int> fin;
        for(auto i:comp) fin.push_back(i.second);
        sort(fin.rbegin(),fin.rend());

        if(fin.size()==1) return fin[0]+1;
        return fin[0]+fin[1]+1;

    }
};