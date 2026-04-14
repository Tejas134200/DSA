class Solution {
public:
    long long ans;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        ans = 1e18;
        vector<int> slot;
        for(auto& f:factory){
            for(int i =0;i<f[1];i++) slot.push_back(f[0]);
        }

        int m  = slot.size();
        vector<vector<long long>> dp(n+1 , vector<long long>(m+1 , ans));

        for(int i =0;i<m+1;i++) dp[0][i]=0;
        for(int i =1;i<n+1;i++){
            for(int j =1;j<m+1;j++){
                dp[i][j] = dp[i][j-1]; //skipp
                dp[i][j] = min(dp[i][j] ,dp[i-1][j-1]+ (long long)abs(robot[i-1]-slot[j-1]));
            }
        }
        return dp[n][m];



    }
};