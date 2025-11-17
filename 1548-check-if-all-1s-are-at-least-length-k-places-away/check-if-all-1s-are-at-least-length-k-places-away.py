class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -k-1
        for ind,i in enumerate(nums):
            if i==1:
                if abs(ind-prev)<=k:
                    return False
                prev = ind

        return True

        