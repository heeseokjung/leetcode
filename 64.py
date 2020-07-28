class Solution:
    def dp(self, i, j, grid):
        if self.cache[i][j] != -1:
            return self.cache[i][j]
        if i == 0 and j == 0:
            self.cache[i][j] = grid[i][j]
        elif i == 0:
            self.cache[i][j] = self.dp(i, j-1, grid) + grid[i][j]
        elif j == 0:
            self.cache[i][j] = self.dp(i-1, j, grid) + grid[i][j]
        else:
            self.cache[i][j] = min(self.dp(i-1, j, grid), self.dp(i, j-1, grid)) + grid[i][j]
        return self.cache[i][j]
    
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        self.cache = [[-1 for j in range(n)] for i in range(m)]
        
        return self.dp(m-1, n-1, grid)