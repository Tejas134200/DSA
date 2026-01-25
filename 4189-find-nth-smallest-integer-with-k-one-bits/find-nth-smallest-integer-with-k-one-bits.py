from math import comb
class Solution:
    def nthSmallest(self, n: int, k: int) -> int:
        ans = 0
        for b in range(62,-1,-1):
            if k>=0 and n>comb(b,k):
                n-=comb(b,k)
                k-=1
                ans|=1<<b
                
        return ans