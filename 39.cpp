class Solution {
public:
    unordered_set<int> s;
    vector<vector<int>> ret;

    void combination(vector<int>& v, vector<int>& candidates, int target) {
        if(target == 0) {
            ret.push_back(v);
            return;
        }

        if(s.find(target) != s.end()) {
            v.push_back(target);
            ret.push_back(v);
            v.pop_back();
        }

        for(int i = 1; i <= target/2; ++i) {
            if(s.find(i) != s.end()) {
                if(v.size() && v.back() > i)
                    continue;
                v.push_back(i);
                combination(v, candidates, target - i);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i = 0; i < (int)candidates.size(); ++i)
            s.insert(candidates[i]);

        vector<int> v;
        combination(v, candidates, target); 

        return ret;
    }
};