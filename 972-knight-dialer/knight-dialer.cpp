class Solution {
public:
    int knightDialer(int n) {
        if(n==1) return 10;
        if(n==2) return 20;
        long long mod = 1e9+7;
        vector<vector<long long>> a = {{2,2,2},{3,0,3},{2,2,2},{0,2,0}};
        int p = n;
        p-=2;
        while(p--){
            vector<vector<long long>> b = {{2,2,2},{3,0,3},{2,2,2},{0,2,0}};
            b[0][0] = (a[1][2]+a[2][1])%mod;
            b[0][1] = (a[2][0]+a[2][2])%mod;
            b[0][2] = (a[1][0]+a[2][1])%mod;
            b[1][0] = (a[0][2]+a[2][2]+a[3][1])%mod;
            b[1][2] = (a[0][0]+a[2][0]+a[3][1])%mod;
            b[2][0] = (a[0][1]+a[1][2])%mod;
            b[2][1] =( a[0][0]+a[0][2])%mod;
            b[2][2] = (a[0][1]+a[1][0])%mod;
            b[3][1] = (a[1][0]+a[1][2])%mod;
            a=b;
        }
        long long ans =0;
        for(auto it:a){
            for(auto i:it) ans = (ans+i)%mod;
        }
        return ans;
    }
};