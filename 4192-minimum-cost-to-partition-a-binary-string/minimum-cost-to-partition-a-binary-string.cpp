class Solution {
public:
    vector<int> pre;
    long long n ;
    long long mini;
    long long en;
    long long fl;

    long long func(int st , int si){
        long long lo = st==0?0:pre[st-1];
        long long hi = pre[st+si-1];
        long long ones = hi-lo;
        long long cost = ones==0?fl:si*en*ones;
        if(si%2==1) return cost;
        return min(cost , func(st,si/2)+func(st+si/2,si/2));
    }
    long long minCost(string s, int encCost, int flatCost) {
         n = s.size();
        pre.resize(n,0);
        int c =0;
        en = encCost;
        fl = flatCost;
        mini = INT_MAX;
        for(int i =0;i<n;i++){
            if(s[i]=='1') c++;
            pre[i]=c;
        }
        return func(0,n);


    }
};