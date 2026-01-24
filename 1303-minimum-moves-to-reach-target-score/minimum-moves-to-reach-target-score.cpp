class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int c =0;
        while(target!=1){
            if(target&1){
                target--;
                c++;
            }
            else{
                if(maxDoubles==0) return c+(target-1);
                else{
                    target/=2;
                    maxDoubles--;
                    c++;
                }
            }
        }
        return c;
    }
};