class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < (int)nums.size(); ++i)
            m.insert(make_pair(nums[i], i));

        vector<int> ans;
        for(int i = 0; i < (int)nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if(it != m.end() && i != it->second) {
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
        }

        return ans;
    }
};