class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans =0;
        if(costBoth<=cost1+cost2){
            long long k = min(need1,need2);
            ans = costBoth*k;
            need1-=k;need2-=k;
            if(costBoth<=cost1) ans+=(long long)costBoth*(long long)need1;
            else ans+=(long long)cost1*need1;
            if(costBoth<=cost2) ans+=(long long)costBoth*(long long)need2;
            else ans+=(long long)cost2*need2;
        }else{
            ans=(long long)need1*cost1+(long long)need2*cost2;
        }
        return ans;
    }
};