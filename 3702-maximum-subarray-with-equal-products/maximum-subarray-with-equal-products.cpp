class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            long long int p = 1 , l = nums[i] , g = nums[i];
            for(int j = i; j<n; j++){
                p *= nums[j];
                l = lcm(l,nums[j]);
                g = gcd(g,nums[j]);

                if(p == g*l)
                ans = max(ans , j-i+1);

                if(p > g*l)
                break;
            }
        }
        return ans;
    }
};