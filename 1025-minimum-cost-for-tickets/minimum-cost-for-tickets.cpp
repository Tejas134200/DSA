class Solution {
public:
    int ans;
    vector<vector<int>> dp;
    int findc(int i , vector<int>& days, vector<int>& costs , int end ){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i][end]!=-1) return dp[i][end];
        if(days[i]<=end){
            return dp[i][end] = findc(i+1 , days , costs , end );
        }else{
            return dp[i][end] = min({costs[0]+findc(i+1 , days , costs , days[i]),
            costs[1]+findc(i+1 , days , costs , days[i]+6),
            costs[2]+findc(i+1 , days , costs , days[i]+29 )});
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n,vector<int>(406,-1));
        return findc(0 , days , costs , 0 );         
    }
};