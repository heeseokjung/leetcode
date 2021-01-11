class Solution:
    def check(self, s_upper, s_lower, t_upper, t_lower):
        for i in range(26):
            if s_upper[i] < t_upper[i]:
                return False
            if s_lower[i] < t_lower[i]:
                return False
        return True
    
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""
        
        s_upper, s_lower = [], []
        t_upper, t_lower = [], []
        for i in range(26):
            s_upper.append(0), s_lower.append(0)
            t_upper.append(0), t_lower.append(0)
            
        for c in t:
            if ord(c) < 97:
                t_upper[ord(c) - ord('A')] += 1
            else:
                t_lower[ord(c) - ord('a')] += 1
                
        if ord(s[0]) < 97:
            s_upper[ord(s[0]) - ord('A')] += 1
        else:
            s_lower[ord(s[0]) - ord('a')] += 1
         
        i, j = 0, 0
        s_size, t_size = len(s), len(t)
        min_size = 100001
        p = [-1, -1]
        while i <= j and i < s_size and j < s_size:
            if self.check(s_upper, s_lower, t_upper, t_lower):
                if j-i+1 < min_size:
                    min_size = j-i+1
                    p[0], p[1] = i, j
                if ord(s[i]) < 97:
                    s_upper[ord(s[i]) - ord('A')] -= 1
                else:
                    s_lower[ord(s[i]) - ord('a')] -= 1
                i += 1
            else:
                j += 1
                if j < s_size and ord(s[j]) < 97:
                    s_upper[ord(s[j]) - ord('A')] += 1
                elif j < s_size and ord(s[j]) >= 97:
                    s_lower[ord(s[j]) - ord('a')] += 1
                    
        if p[0] == -1 and p[1] == -1:
            return ""
        else:
            return s[p[0]:p[1]+1]