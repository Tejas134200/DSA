class Solution {
public:
    const int MOD = 1e9+7;
    int dp[100001][2][3];

    int solve(int pos,int a,int l,int n){

        if(pos==n) return 1;

        if(dp[pos][a][l]!=-1)
            return dp[pos][a][l];

        long long ans=0;

        
        ans += solve(pos+1,a,0,n);

        
        if(a==0)
            ans += solve(pos+1,1,0,n);

        
        if(l<2)
            ans += solve(pos+1,a,l+1,n);

        return dp[pos][a][l]=ans%MOD;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n);
    }
};