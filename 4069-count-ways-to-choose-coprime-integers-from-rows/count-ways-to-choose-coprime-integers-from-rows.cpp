class Solution {
public:
    int mod;
    int solve(int i,int curg ,vector<vector<int>>& mat , vector<vector<int>>& dp ){
        if(i>=mat.size()) return curg==1;
        if(dp[i][curg]!=-1) return dp[i][curg];
        int curans=0;
        for(int j=0;j<mat[i].size();j++)
            {
                int naya=__gcd(curg,mat[i][j]);
                curans=(curans%mod+solve(i+1,naya,mat,dp)%mod)%mod;
            }
        return dp[i][curg]=curans;
    }
    int countCoprime(vector<vector<int>>& mat) {
        mod = 1e9+7;
         vector<vector<int>>dp(mat.size(),vector<int>(151,-1));

        return solve(0,0,mat,dp);
        
    }
};