class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n, mx = len(nums), 0
        for i in range(n):
            if i <= mx and i + nums[i] > mx:
                mx = i + nums[i]
        
        return mx >= n-1