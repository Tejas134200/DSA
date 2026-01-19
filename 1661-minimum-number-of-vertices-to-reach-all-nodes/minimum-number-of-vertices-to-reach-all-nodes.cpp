class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inde(n,0);
        for(auto v:edges){
            inde[v[1]]++;
        }
        
        vector<int> ans;
        for(int i =0;i<n;i++) if(inde[i]==0) ans.push_back(i);
        return ans;


    }
};