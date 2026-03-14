class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2,m3;

        for(int i:nums1) {m1[i]++;m3[i]++;}
        for(int i:nums2){
            m2[i]++;
            m3[i]++;
        }
        int c =0;
        for(auto it:m3){
            int e = it.first;
            int f = it.second;
            if(f%2==1) return -1;
            if(m1[e]==f/2&&m2[e]==f/2) c+=0;
            else{
                c+=abs(f/2-m1[e]);
            }
        }
        return c/2;
    }
};