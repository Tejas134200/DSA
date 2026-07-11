class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1 , vector<int>(n,-1));
        for(int i =0;i<n;i++) dp[m][i]=i;

        for(int i = m-1;i>=0;i--){
            for(int j =0;j<n;j++){
                if(j==0&&grid[i][j]==-1){
                    
                    continue;
                }
                if(j==n-1&&grid[i][j]==1) {
                    
                    continue;
                }

                if(grid[i][j]==1&&grid[i][j+1]==1){
                    dp[i][j] = dp[i+1][j+1];
                }
                if(grid[i][j]==-1&&grid[i][j-1]==-1){
                    dp[i][j]=dp[i+1][j-1];
                }




            }
        }

        return dp[0];
    }
};