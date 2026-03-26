class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        long long ans =0;
        long long hi = n;
        long long lo = n;
        long long nn = n;
        n--;
        while(n>0){
            ans+=(max(hi , lo )*n);
            if(hi>lo) hi=n;
            else lo = n;
            n--;
        }
        if(edges.size()==nn) ans+=(hi*lo);
        return ans;
    }
};