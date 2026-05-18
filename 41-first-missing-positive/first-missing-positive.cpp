class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> m;
        for(int i:nums) if(i>0) m[i]++;
        int prev= 0;
        for(auto it:m){
            if(it.first>prev+1) return prev+1;
            prev = it.first;
        }
        return prev+1;
    }
};