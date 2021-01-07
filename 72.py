class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        size1 = len(word1)
        size2 = len(word2)
        
        d = []
        for i in range(size1+1):
            tmp = []
            for j in range(size2+1):
                tmp.append(0)
            d.append(tmp)
                
        for i in range(1, size1+1):
            d[i][0] = i
        for i in range(1, size2+1):
            d[0][i] = i
            
        for i in range(1, size1+1):
            for j in range(1, size2+1):
                if i > 0 and j > 0 and word1[i-1] == word2[j-1]:
                    d[i][j] = d[i-1][j-1]
                else:
                    d[i][j] = min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1]) + 1
        
        return d[size1][size2]