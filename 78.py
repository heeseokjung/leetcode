class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        ret.append([])
        pos = 1
        size = len(nums)
        
        while pos < (1<<size):
            p = 0
            s = []
            while (1<<p) <= pos:
                if (1<<p) & pos:
                    s.append(nums[p])
                p += 1
            if s:
                ret.append(s)
            pos += 1
            
        return ret