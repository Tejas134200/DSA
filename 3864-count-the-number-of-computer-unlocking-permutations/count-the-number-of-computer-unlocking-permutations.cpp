#include <vector>
#include <algorithm>

class Solution {
private:
    const long long MOD = 1000000007;

    long long factorial(int n) {
        long long result = 1;
        for (int i = 1; i <= n; ++i) {
            result = (result * i) % MOD;
        }
        return result;
    }

public:
    int countPermutations(std::vector<int>& complexity) {
        int n = complexity.size();
        
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }
        
       
        return factorial(n - 1);
    }
};