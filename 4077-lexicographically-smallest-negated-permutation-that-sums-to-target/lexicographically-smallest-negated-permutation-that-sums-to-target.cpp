class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S = 1LL * n * (n + 1) / 2;
        if(target>S || target<-S) return {};
        if((S-target)%2!=0) return {};
        long long x = (S-target)/2;
        vector<int> sign(n+1,1);
        for(int i = n;i>0;i--){
            if(i<=x){
                sign[i]=-1;
                x-=i;
            }
        }
        vector<int> ans(n);
        for(int i =1;i<=n;i++){
            ans[i-1]=i*sign[i];
        }
        sort(ans.begin(),ans.end());
        return ans;
        

        
    }
};