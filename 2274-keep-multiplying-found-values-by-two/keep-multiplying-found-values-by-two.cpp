class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int> m;
        for(int i:nums) m[i]++;
        while(m.count(original)) original*=2;
        return original;
    }
};