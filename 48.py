class Solution:
    def swap(self, a, b):
        return (b, a)
    
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        for i in range(size):
            for j in range(i, size):
                matrix[i][j], matrix[j][i] = self.swap(matrix[i][j], matrix[j][i])
        for j in range(size//2):
            for i in range(size):
                matrix[i][j], matrix[i][size-1-j] = self.swap(matrix[i][j], matrix[i][size-1-j])