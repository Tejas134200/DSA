class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s=0;
        vector<int> a;
        for(int i:nums){
            s+=i;
            a.push_back(s);
        }
        int c =0;
        for(int i =0;i<nums.size()-1;i++){
            if((s-2*a[i])%2==0) c++;
        }
        return c;
    }
};