class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n+1,0);
        v[1]=1;
        v[2]=1;
        if(n==2) return 1;
        v[3]=2;
        for(int i=4;i<=n;i++){
            int maxi = -1;
            for(int j =1;j<i;j++){
                maxi = max(maxi, max(j, v[j]) * max(i - j, v[i - j]));
            }
            v[i]=maxi;
        }
        return v[n];
    }
};