class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unordered_set<int>>> vec(m , vector<unordered_set<int>>(n));

        vec[0][0].insert(grid[0][0]);
        for(int i =1;i<n;i++){
            for(auto &ii:vec[0][i-1]){
                vec[0][i].insert(ii^grid[0][i]);
            }
        }
        for(int i =1;i<m;i++){
            for(auto &ii:vec[i-1][0]){
                vec[i][0].insert(ii^grid[i][0]);
            }
        }

        for(int i =1;i<m;i++){
            for(int j = 1;j<n;j++){
                for(auto &ii:vec[i-1][j]) vec[i][j].insert(ii^grid[i][j]);
                for(auto &ii:vec[i][j-1]) vec[i][j].insert(ii^grid[i][j]);
            }
        }
        int mini = INT_MAX;
        for(auto &ii:vec[m-1][n-1]) mini = min(mini , ii);
        return mini;
        



    }
};