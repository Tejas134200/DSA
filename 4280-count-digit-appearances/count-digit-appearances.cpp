class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans =0;
        for(int n:nums){
            while(n>0){
                int i = n%10;
                if(i==digit) ans++;
                n/=10;
            }
        }
        return ans;
    }
};