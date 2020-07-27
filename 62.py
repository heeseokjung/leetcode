class Solution:
    def __init__(self):
        self.cache = [[-1 for j in range(201)] for i in range(201)]
        
    def comb(self, n: int, r: int) -> int:
        if n == r:
            self.cache[n][r] = 1
            return self.cache[n][r]
        if self.cache[n][r] != -1:
            return self.cache[n][r]
        cache[n][r] = self.comb(n-1, r-1) + self.comb(n-1, r)
        return cache[n][r]
    
    def uniquePaths(self, m: int, n: int) -> int:
        return comb(m+n-2, n-1)