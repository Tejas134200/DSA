import math

class Solution:
    def countVisiblePeople(self, n: int, pos: int, k: int) -> int:
        MOD = 10**9 + 7
        
        if k > n - 1:
            return 0
            
        combinations = math.comb(n - 1, k)
        
        return (combinations * 2) % MOD
