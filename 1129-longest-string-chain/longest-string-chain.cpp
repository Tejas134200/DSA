class Solution {
public:

    bool checkP(string a , string b){
        if(a.size()+1!=b.size()) return false;
        int i =0;
        int j =0;
        while(j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==a.size()&&j==b.size()) return true;
        return false;

    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](const string& a,const string& b){return a.size()<b.size();});
        int maxi = INT_MIN;
        vector<int> dp(n,1);
        for(int i =0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(checkP(words[j],words[i])&&dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi =max(maxi , dp[i]);
        }
        return maxi;
    }
};