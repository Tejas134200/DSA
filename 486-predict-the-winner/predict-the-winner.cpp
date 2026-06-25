class Solution {
public:
    bool find(int i , int j ,int a , int b , vector<int>& nums,bool isa=true){
        if(i>j) return a>=b;
        if(isa) return find(i+1,j,a+nums[i],b,nums,false)||find(i,j-1,a+nums[j],b,nums,false);

        return find(i+1,j,a,b+nums[i],nums,true)&&find(i,j-1,a,b+nums[j],nums,true);

    }
    bool predictTheWinner(vector<int>& nums) {
        return find(0,nums.size()-1,0,0,nums);
    }
};