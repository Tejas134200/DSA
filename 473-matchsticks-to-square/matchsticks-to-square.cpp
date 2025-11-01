class Solution {
public:
vector<int> dp;
    bool findc(int i , vector<int>& mats , int len ){
        if(i==mats.size()) return true;

        for(int j =0;j<4;j++){
            if(dp[j]+mats[i]<=len){
                dp[j]+=mats[i];
                if(findc(i+1,mats,len)){
                    return true;
                }
                dp[j]-=mats[i];
            }

        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i :matchsticks) sum+=i;
        if(sum!=(sum/4)*4) return false;
         dp={0,0,0,0};
         sort(matchsticks.rbegin(),matchsticks.rend());
        return findc(0,matchsticks,sum/4);
    }
};