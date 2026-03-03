class Solution {
public:
    int binaryGap(int n) {
        vector<int> bit(32,0);
        for(int i=0;i<32;i++) bit[i] = (n&(1<<i))?1:0;
        int maxi =0;
       int i =0;
       while(i<32&&bit[i]==0) i++;
       int prev= i;
       if(i==32) return 0;
        i++;
       while(i<32){
            if(bit[i]==1){
                maxi = max(maxi , i-prev);
                prev =i;
            }
            i++;
       }
        return maxi;
    }
};