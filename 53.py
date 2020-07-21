class Solution:
    def divide(self, nums, s, e):
        if s == e:
            return nums[s]
        
        m = (s + e)//2
        lmax, sum = -inf, 0
        for i in range(m, s-1, -1):
            sum += nums[i]
            lmax = max(lmax, sum)
        rmax, sum = -inf, 0
        for i in range(m+1, e+1):
            sum += nums[i]
            rmax = max(rmax, sum)
            
        return max(lmax + rmax, self.divide(nums, s, m), self.divide(nums, m+1, e))
    
    def maxSubArray(self, nums: List[int]) -> int:
        return self.divide(nums, 0, len(nums)-1)