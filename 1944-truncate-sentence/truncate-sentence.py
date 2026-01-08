class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        li = list(s.split(" "))
        ans=""
        for i in range(0,k):
            ans+=li[i]
            if i!=k-1:
                ans+=" "
        return ans        
