class Solution:
    def comb(self, n, r):
        if n == r:
            return 1
        elif self.cache[n][r] != -1:
            return self.cache[n][r]
        self.cache[n][r] = self.comb(n-1, r-1) + self.comb(n-1, r)
        return self.cache[n][r]
    
    def climbStairs(self, n: int) -> int:
        self.cache = [[-1 for j in range(n)] for i in range(n)]
        i, count = 0, 0
        while(i*2 <= n):
            j = n - 2*i
            count += comb(i+j, j)
            i += 1
        return count