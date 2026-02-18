class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n+1,1);
        t[0]=1;
        t[1]=1;
        if(n==1) return 1;
        t[2] =2;
        for(int i =3;i<=n;i++){
            int ans =0;
            for(int j =1;j<=i;j++){
                int l = j-1;
                int r = i-j;
                ans+=(t[l]*t[r]);
            }
            t[i] = ans;
        }
        return t[n];


        
    }
};