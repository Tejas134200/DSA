class Solution {
public:
    vector<int> par, r;

    int find(int a){
        if(par[a] != a) par[a] = find(par[a]);
        return par[a];
    }

    void unionf(int a, int b){
        int aa = find(a);
        int bb = find(b);

        if(aa == bb) return;

        par[bb]=aa;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        par.resize(n);
        r.resize(n,0);

        for(int i=0;i<n;i++) par[i] = i;

        vector<int> ans;

        for(auto &i:edges) unionf(i[0], i[1]);

        unordered_map<int,int> mp;

        for(auto &i:edges){
            int p = find(i[0]);
            if(mp.find(p) == mp.end()) mp[p] = i[2];
            else mp[p] &= i[2];
        }

        for(auto &i:query){
            int p = find(i[0]);
            int q = find(i[1]);
            if(p != q) ans.push_back(-1);
            else ans.push_back(mp[p]);
        }

        return ans;
    }
};