class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j , vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int l = i;l<=j;l++){
            int score = nums[i-1]*nums[l]*nums[j+1]+f(i,l-1,nums)+f(l+1,j,nums);
            maxi=max(maxi , score);
        }
        return dp[i][j]=maxi;


    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        dp.resize(n+1,vector<int>(n+1,-1));
        
        nums.insert(nums.begin(),1);
        return f(1,n,nums);

    }
};