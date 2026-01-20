class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n  = recipes.size();
        vector<vector<int>> adj(n,vector<int>());
        unordered_map<string,int> mp;
        for(string s:supplies) mp[s]++;
        vector<string> ans;
        vector<bool> vis(n,false);
        for(int i =0;i<n;i++){
            int c =0;
            for(string ing:ingredients[i]){
                if(mp[ing]>0) {
                    c++;
                }
            }
            if(c==ingredients[i].size()) {ans.push_back(recipes[i]);mp[recipes[i]]++;vis[i]=true;}
        }
        while(true){
            int k = ans.size();
            for(int i =0;i<n;i++){
                if(!vis[i]){
                    int c =0;
                    for(string ing:ingredients[i]){
                    if(mp[ing]>0) c++;
                    }
                    if(c==ingredients[i].size()) {ans.push_back(recipes[i]);mp[recipes[i]]++;vis[i]=true;}

                    
            
                }
            }
            if(ans.size()==k||ans.size()==n) return ans;

        }
        return {};
    }
};