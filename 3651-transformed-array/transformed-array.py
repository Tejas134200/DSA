class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr =[0]*n
        for i in range(0,n):
            k = nums[i]
            if k>0:
                arr[i] = nums[(i+k+n)%n]
            
            elif k<0:
                t = abs(k)
                arr[i] = nums[(i-t+n)%n]
            else:
                arr[i]=0


        return arr