class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        max_idx, tmp, ans = 0, 0, 0
        for i in range(n):
            max_idx = max(max_idx, i + nums[i])
            if max_idx >= n-1 and i != n-1:
                ans += 1
                return ans
            if i == tmp and i != n-1:
                ans += 1
                tmp = max_idx
        return ans