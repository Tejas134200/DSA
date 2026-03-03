class Solution {
public:
    bool isp(int x){
        if(x==1) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans =0;
        for(int i = left;i<=right;i++){
            if(isp(__builtin_popcount(i))) ans++;
        }
        return ans;
    }
};