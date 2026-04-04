class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int mini = 1000;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((nums[i]==1&&nums[j]==2)||(nums[i]==2&&nums[j]==1)) mini = min(mini , j-i);
            }
        }
        return mini==1000?-1:mini;
    }
};