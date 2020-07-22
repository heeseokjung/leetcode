class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort()
        ans = []
        s = e = None
        for idx, interval in enumerate(intervals):
            if idx == 0:
                s = interval[0]
                e = interval[1]
            else:
                if interval[0] > e:
                    ans.append([s, e])
                    s = interval[0]
                    e = interval[1]
                else:
                    e = max(e, interval[1])
        ans.append([s, e])
                    
        return ans