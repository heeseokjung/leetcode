class Solution:
    def swap(self, a, b):
        return (b, a)
    
    def run(self, s, e):
        if(s == e):
            tmp = []
            for i in self.nums:
                tmp.append(i)
            self.ans.append(tmp)
            return
        for i in range(s, e+1):
            self.nums[s], self.nums[i] = self.swap(self.nums[s], self.nums[i])
            self.run(s+1, e)
            self.nums[s], self.nums[i] = self.swap(self.nums[s], self.nums[i])
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.nums = nums
        self.n = len(nums)
        self.ans = []
        
        self.run(0, self.n-1)
        
        return self.ans