class Solution {
public:
    int binExpo(long long a,long long b,int M){
        long long ans=1;
        while(b){
            if(b&1){
                ans=(1LL*ans*a)%M;
            }
            a=(1LL*a*a)%M;
            b>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int numB=0;
        int n=b.size();
        for(int i=n-1;i>=0;i--){
            numB=(numB+b[i]*binExpo(10,n-1-i,1140))%1140;
        }
        if(numB==0) numB=1140;
        int ans=binExpo(a,numB,1337);
        return ans;
    }
};