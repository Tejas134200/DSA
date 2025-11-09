class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        int dis = INT_MAX;
        for(int i =0;i<n;i++){

            if(mp[nums[i]].size()==2){
                 dis = min(dis,abs(mp[nums[i]][0]-mp[nums[i]][1])+abs(mp[nums[i]][0]-i)+abs(mp[nums[i]][1]-i));
            }
            if(mp[nums[i]].size()>=2){
                mp[nums[i]].erase(mp[nums[i]].begin());
            }mp[nums[i]].push_back(i);
            
            
        }
        return dis==INT_MAX?-1:dis;
    }
};