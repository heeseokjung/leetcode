class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_strs = []
        for s in strs:
            sorted_strs.append(str(sorted(s)))
            
        group = {}
        for i, s in enumerate(sorted_strs):
            if s in group:
                group[s].append(i)
            else:
                group[s] = [i]
                
        ans = []
        for k in group.keys():
            tmp = []
            for i in group[k]:
                tmp.append(strs[i])
            ans.append(tmp)
            
        return ans