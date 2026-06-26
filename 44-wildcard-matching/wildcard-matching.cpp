class Solution {
public:
vector<vector<int>> dp;
    bool find(int i , int j , string& s , string& p){
        if(j==p.size()){
            return dp[i][j] =( i==s.size());
        }
        if(i==s.size()) {
            while(j < p.size()){
        if(p[j] != '*')  return dp[i][j] =false;
        j++;
    }
    return dp[i][j] = true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        bool match = s[i]==p[j]||p[j]=='?';
        if(p[j]=='*'){
            return dp[i][j]= find(i+1,j,s,p)||find(i,j+1,s,p);
        }
        return dp[i][j] = match&&find(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
         dp.resize(s.size()+1 , vector<int>(p.size()+1,-1));
        return find(0,0,s,p);
    }
};