class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int tsum = 0;
        for(char c:s1) tsum+=c;
        for(char c:s2) tsum+=c;

        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] += s1[0]==s2[0]?s1[0]+0:0;
        for(int i =1;i<m;i++){
            
            dp[0][i] = dp[0][i-1];
            if(s1[0]==s2[i]) dp[0][i]=s1[0]+0;
        }
        for(int i =1;i<n;i++){
            dp[i][0] = dp[i-1][0];
            if(s1[i]==s2[0]) dp[i][0]=s2[0]+0;
        }

        for(int i =1;i<n;i++){
            for(int j =1;j<m;j++){
                if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+s1[i];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return tsum-2*dp[n-1][m-1];



    }
};