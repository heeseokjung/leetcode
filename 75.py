class Solution:
    def sortColors(self, nums: List[int]) -> None:
        size = len(nums)
        count = [0, 0, 0]
        
        for i in range(size):
            count[nums[i]] += 1
            
        k = 0    
        for i in range(3):
            for j in range(count[i]):
                nums[k] = i
                k += 1