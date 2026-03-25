class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,long long> mp;
        for(auto &i:wall){
            long long e =0;
            for(int j =0;j<i.size()-1;j++){
                e+=i[j];
                mp[e]++;
            }
        }
        long long maxi = 0;
        for(auto it:mp){
            maxi =max(maxi , it.second);
        }
        return wall.size()-maxi;
    }
};