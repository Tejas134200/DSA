class Solution {
public:
    int numSquares(int n) {
        vector<int> a(101,0);
        for(int i =1;i<=100;i++) a[i]=i*i;
        vector<int> v(n+1,0);
        if(n==1) return 1;
        if(n==2) return 2;
        v[1]=1;
        v[2]=2;
        for(int i=3;i<=n;i++){
            int mini=INT_MAX;
            for(int j =1;j<=100;j++){
                if(a[j]>i) break;
                mini = min(mini , 1+v[i-a[j]]);

            }
            v[i]=mini;
        }
        return v[n];

    }
};