class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del = 0;
        int len = 0;

        for(int i = 0; i < nums.size(); i++){
            if(len % 2 == 0){
                len++;
            }
            else{
                if(nums[i] == nums[i-1]) del++;
                else len++;
            }
        }

        if(len % 2) del++;
        return del;
    }
};