class Solution {
public:
    long long countCommas(long long n) {
        // if(n<1000) return 0;
        // if(n<1000000) return n-1000+1;
        // if(n<1000000000) return (n-1000000+1)*2-(999999-1000+1);
        // if(n<1000000000000) return (n-1000000000+1)*3-(999999999-1000000+1)-2*(999999-1000+1);
        // if(n<1000000000000000) return (n-1000000000000)*4-(999999999999999-1000000000000+1)-2*(999999999-1000000+1)-3*(999999-1000+1);
        // return 5;

        long long ans =0;
        long long st = 1000;
        long long comma = 1;

        while(st<=n){
            long long e = st*1000-1;
            long long cnt = min(n ,e)-st+1;
            ans+=(cnt*comma);
            comma++;
            st*=1000;

            
        }
        return ans;


        
        
    }
};