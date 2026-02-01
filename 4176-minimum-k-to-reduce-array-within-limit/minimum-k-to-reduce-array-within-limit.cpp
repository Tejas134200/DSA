class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long n = nums.size();
        sort(nums.begin(),nums.end());
        long long l =1;
        long long h = 1000001;
        while(l<=h){
            long long m = l+(h-l)/2;
            int c =0;
            for(int i:nums){
                c+=(i+m-1)/m;
            }
            if(c<=m*m) h =m-1;
            else l = m+1;
        }
        return l;
    }
};