class Solution {
public:
    int maximumAmount(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        for(int k = 0; k < 3; k++){
            if(a[0][0] >= 0) dp[0][0][k] = a[0][0];
            else{
                if(k > 0) dp[0][0][k] = 0;
                else dp[0][0][k] = a[0][0];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                for(int k = 0; k < 3; k++){
                    int best = -1e9;

                    if(i > 0) best = max(best, dp[i-1][j][k]);
                    if(j > 0) best = max(best, dp[i][j-1][k]);

                    if(a[i][j] >= 0){
                        dp[i][j][k] = best + a[i][j];
                    } 
                    else{
                        int take = best + a[i][j];

                        int skip = -1e9;
                        if(k > 0){
                            if(i > 0) skip = max(skip, dp[i-1][j][k-1]);
                            if(j > 0) skip = max(skip, dp[i][j-1][k-1]);
                        }

                        dp[i][j][k] = max(take, skip);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};