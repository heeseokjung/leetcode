class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums:
            return 1
        
        size = len(nums)
        is_one = False
        for i in range(size):
            if nums[i] == 1:
                is_one = True
            elif nums[i] <= 0 or nums[i] > size:
                nums[i] = 1
                
        if not is_one:
            return 1
                
        for i in range(size):
            j = abs(nums[i]) - 1
            if nums[j] > 0:
                nums[j] = -nums[j]
                
        for i in range(size):
            if nums[i] > 0:
                return i + 1
            
        return size + 1
                