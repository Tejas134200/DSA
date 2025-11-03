class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =0;
        int i =0;
        while(i<colors.size()){
            char c = colors[i];
            int mini = -1;
            int count=0;
            int sum=0;
            while(colors[i]==c){
                mini = max(mini , neededTime[i]);
                sum+=neededTime[i];
                i++;
                count++;
            }
            cout<<sum<<" "<<mini;
            if(count>1) ans+=(sum-mini);
        }
        return ans;
    }
};