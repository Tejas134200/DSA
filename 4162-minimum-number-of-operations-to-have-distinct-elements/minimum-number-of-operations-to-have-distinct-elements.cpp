class Solution {
public:
    int minOperations(vector<int>& nums) {
        int dupc = 0;
        unordered_map<int,int> m;
        set<int> s;

        for(int i:nums){
            m[i]++;
            if(m[i]>1) {
                if(s.find(i)==s.end()) s.insert(i);
            }
        }
        dupc= s.size();
        if(dupc==0) return 0;
        int c =0;
        int i =0;
        while(i<nums.size()){
            for(int j =i;j<i+3&&j<nums.size();j++){
                m[nums[j]]--;
                if(m[nums[j]]==1) dupc--;
            }
            i+=3;
            c++;
            if(dupc==0) return c;
        }
        return c;
         
    }
};