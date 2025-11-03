class Solution {
public:
    int n,m;
    int dfs(int i,int j , vector<vector<int>>& dun , vector<vector<int>>& dp){
        if(i>=n||j>=m) return -1e5;
        if(i==n-1 && j==m-1) return dun[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=dun[i][j];
        int res=dun[i][j]+max(dfs(i+1, j,dun, dp), dfs(i, j+1,dun, dp));
        return dp[i][j]=min(ans, res);


    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
         m = dungeon[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int res = dfs(0,0,dungeon,dp);
        return res>=0?1:-1*res+1;
        
    }
};