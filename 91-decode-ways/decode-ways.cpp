class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==1) {
            if(s[0]=='0') return 0;
            return 1;
        }
        vector<int> t(n,0);
        if(s[0]!='0') t[0]=1;
        int k = 10*(s[0]-'0')+(s[1]-'0');
        if(k>=10 && k<=26) t[1]+=1;
        if(s[1]-'0'!=0) t[1]+=t[0];
        for(int i =2;i<n;i++){
            int k = 10*(s[i-1]-'0')+(s[i]-'0');
            int th = s[i]-'0';
            if(th!=0) t[i]+=t[i-1];
            if(k>=10&&k<=26) t[i]+=t[i-2];
        } 
        return t[n-1];
    }
};