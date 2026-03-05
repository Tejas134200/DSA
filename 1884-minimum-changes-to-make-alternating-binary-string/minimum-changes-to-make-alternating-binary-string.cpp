class Solution {
public:
    int minOperations(string s) {
        int c1 =0,c2=0;
        for(int i =0;i<s.size();i++){
            if(!(i%2)){
                s[i]=='1'?c1++:c2++;                
            }else{
                s[i]=='1'?c2++:c1++;
            }
        }
        return min(c1 , c2);
    }
};