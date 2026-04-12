class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> sieve(100004 , 1);
        sieve[1]=0;
        for(long long i=2;i<100004;i++){
            for(long long j = i+i;j<100004;j+=i){
                sieve[j]=0;
            }
        }
        int ans =0;
        for(int i =0;i<nums.size();i++){
            if(i%2==0){
                if(sieve[nums[i]]==0){
                    int in = nums[i];
                    int c = 0;
                    while(in<100004&&sieve[in++]==0) c++;
                    ans+=c;
                }
                
            }else{
                if(sieve[nums[i]]==1) nums[i]==2?ans+=2:ans++;
            }
        }
        return ans;


    }
};