class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[arr[i]]=i;

        vector<vector<int>> dp(n,vector<int>(n,2));

        int ans=0;

        for(int j=0;j<n;j++){

            for(int i=0;i<j;i++){

                int prev=arr[j]-arr[i];

                if(mp.count(prev)){

                    int k=mp[prev];

                    if(k<i){

                        dp[i][j]=dp[k][i]+1;

                        ans=max(ans,dp[i][j]);
                    }
                }
            }
        }

        return ans>=3?ans:0;
    }
};