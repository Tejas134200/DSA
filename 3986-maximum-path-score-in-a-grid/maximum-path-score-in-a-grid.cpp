class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(k+1,-1)));
        dp[0][0][0]=0;
        for(int i =1;i<m;i++){
            int cost = grid[0][i]>0?1:0;
            int sc = grid[0][i];
            for(int j =0;j<=k;j++){
                if(dp[0][i-1][j]!=-1){
                    int tc = j+cost;
                    if(tc<=k) dp[0][i][tc] = dp[0][i-1][j]+sc;

                }
            }
        }
        for(int i =1;i<n;i++){
            int cost = grid[i][0]>0?1:0;
            int sc = grid[i][0];
            for(int j =0;j<=k;j++){
                if(dp[i-1][0][j]!=-1){
                    int tc = j+cost;
                    if(tc<=k) dp[i][0][tc] = dp[i-1][0][j]+sc;
                    

                }
            }
        }

        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                int cost = grid[i][j]>0?1:0;
                int sc = grid[i][j];
                for(int kk = 0;kk<=k;kk++){
                    int coo = cost+kk;
                    int xx = max(dp[i-1][j][kk]  , dp[i][j-1][kk]);
                    if(coo<=k) dp[i][j][coo] = xx==-1?-1:xx+sc;
                }
            }
        }
        int maxi = -1;
        for(int i = 0;i<=k;i++) maxi = max(maxi , dp[n-1][m-1][i]);
        return maxi;

    }
};