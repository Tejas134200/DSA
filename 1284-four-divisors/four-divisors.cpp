class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int ans = 0;
         for(int num:nums){
            int sd =0;
            int c =0;
            for(int i=1;i<=sqrt(num);i++){
                if(num%i==0){
                    sd+=i;
                    sd+=(num/i);
                    c+=2;
                }
                if(i*i==num){
                        c--;
                        sd-=i;
                }
                if(c>4){
                        break;
                }
                
            }
            if(c==4) ans+=sd;
         }
         return ans;
    }
};