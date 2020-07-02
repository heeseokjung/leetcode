class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        lmax = [0 for i in range(n)]
        rmax = [0 for i in range(n)]
        
        mx = 0
        for i in range(1, n):
            if mx < height[i-1]:
                mx = height[i-1]
            lmax[i] = mx
            
        mx = 0
        for i in reversed(range(n-1)):
            if mx < height[i+1]:
                mx = height[i+1]
            rmax[i] = mx
            
        sum = 0
        for i in range(n):
            w = 1
            h = min(lmax[i], rmax[i]) - height[i]
            if h <= 0:
                continue
            sum += h * w
            
        return sum