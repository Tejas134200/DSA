class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(int node,vector<int> ta,vector<vector<int>>& graph){
        if(node==n-1){
            ans.push_back(ta);
            return;
        }
        for(int i:graph[node]){
            ta.push_back(i);
            dfs(i,ta,graph);
            ta.pop_back();
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> ta;
        ta.push_back(0);
        dfs(0,ta,graph);
        return ans;  
    }
};