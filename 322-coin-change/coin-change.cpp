class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> v(n+1,0);
        sort(coins.begin(),coins.end());
        if(amount==0) return 0;
        v[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j =0;j<coins.size();j++){
                if(coins[j]>i) break;
                if(v[i-coins[j]]!=-1){
                    mini = min(mini , 1+v[i-coins[j]]);
                }

            }
            v[i]= mini==INT_MAX?-1:mini;
        }
        return v[n];
    }
};