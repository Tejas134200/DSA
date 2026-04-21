class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long MOD = 1e9 + 7;
        long long xori = 0;
        
        long long ax = 0, bx = 0;
        
        for (int i = 49; i >= n; i--) {
            if ((a >> i) & 1) ax ^= (1LL << i);
            if ((b >> i) & 1) bx ^= (1LL << i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int aa = (a >> i) & 1;
            int bb = (b >> i) & 1;
            
            if (aa == bb) {
                
                ax ^= (1LL << i);
                bx ^= (1LL << i);
            } else {
                
                if (ax > bx) {
                    bx ^= (1LL << i);
                } else {
                    ax ^= (1LL << i);
                }
            }
        }
        
        return (ax % MOD) * (bx % MOD) % MOD;
    }
};