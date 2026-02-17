class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost[0];
        int y = cost[1];
        for(int i=2;i<cost.size();i++){
            int z = min(x,y)+cost[i];
            x = y;
            y= z;
        }
        return min(x,y);
    }
};