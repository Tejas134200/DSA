class Solution {
public:
    vector<int> par;

    int find(int x){
        if(par[x] != x)
            par[x] = find(par[x]); 
        return par[x];
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(pu < pv) par[pv] = pu;
        else par[pu] = pv;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26);
        for(int i = 0; i < 26; i++) par[i] = i;

        for(int i = 0; i < s1.size(); i++){
            unite(s1[i]-'a', s2[i]-'a');
        }

        string ans = "";
        for(char c : baseStr){
            int root = find(c - 'a');
            ans += (char)(root + 'a');
        }

        return ans;
    }
};