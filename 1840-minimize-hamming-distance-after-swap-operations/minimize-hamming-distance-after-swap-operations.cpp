class Solution {
public:
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int u , int v){
        int uu = find(u);
        int vv = find(v);

        if(uu==vv) return;
        par[uu]=vv;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        par.resize(1000001);
        int n = source.size();
        for(int i =0;i<par.size();i++) par[i]=i;

        for(auto fs : allowedSwaps){
            unite(fs[0] , fs[1]);
            

        }

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[find(i)].push_back(i);
        }


    int ans = 0;

    for(auto &it : mp){
    unordered_map<int,int> freq;

    for(int idx : it.second){
        freq[source[idx]]++;
    }

    for(int idx : it.second){
        if(freq[target[idx]] > 0){
            freq[target[idx]]--;
        } else {
            ans++;  
        }
    }
}
    return ans;



    }
};