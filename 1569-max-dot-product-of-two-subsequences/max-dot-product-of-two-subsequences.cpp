class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = nums1[0]*nums2[0];
        for(int i =1;i<m;i++) dp[0][i]=max(nums1[0]*nums2[i],dp[0][i-1]);
        for(int i =1;i<n;i++) dp[i][0]=max(nums2[0]*nums1[i],dp[i-1][0]);
        for(int i =1;i<n;i++){
            for(int j =1;j<m;j++){
                dp[i][j] = max({
    dp[i-1][j],
    dp[i][j-1],
    nums1[i] * nums2[j],
    nums1[i] * nums2[j] + dp[i-1][j-1]
});
            }
        }
        return dp[n-1][m-1];
    }
};