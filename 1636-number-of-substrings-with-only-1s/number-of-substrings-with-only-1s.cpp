class Solution {
public:
    int numSub(string s) {
        int mod =1e9+7;
        long long c =0;
        long long ans =0;
        for(char ch:s){
            if(ch=='0'){
                ans = (ans+((c)*(c+1)/2)%mod)%mod;
                c=0;
            }else c++;
        }
        ans = (ans+((c)*(c+1)/2)%mod)%mod;
        return ans;
    }
};