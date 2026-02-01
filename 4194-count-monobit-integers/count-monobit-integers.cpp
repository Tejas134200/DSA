class Solution {
public:
    int countMonobit(int n) {
        int ans =1;
        int c= 2;
        while(c-1<=n){
            ans++;
            c*=2;
        }
        return ans;
    }
};