class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long k=(n^(n>>1));
        return !(k&(k+1));

    }
};