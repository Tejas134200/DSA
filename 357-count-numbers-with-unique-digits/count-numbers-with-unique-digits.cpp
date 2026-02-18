class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        int res = 10;
        int cur =9;
        for(int i =2;i<=n;i++){
            cur*=(10-(i-1));
            res+=cur;
        }
        return res;
    }
};