class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int tt=num;
        int ss= sum;
        while(num--){
            int k = sum>9?9:sum;
            sum = sum-k;
            ans+=to_string(k);
        }
        int co = 0;
        for(int i =0;i<tt;i++){
            co +=(ans[i]-'0');
        }
        return co==ss?ans:"";

        
    }
};