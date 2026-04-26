class Solution {
public:
    bool validDigit(int n, int x) {
        int prev;
        int c =0;
        while(n>0){
            int k = n%10;
            n/=10;
            if(k==x) {
                c++;
                
            }
            prev = k;
        }
        if(prev==x) return false;
        return c>0;
    }
};