class Solution {
public:
    int starting_position(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size()-1;
        int pos = -1;
        while(l <= r) {
            int m = (l + r)/2;
            if(nums[m] <= target) {
                if(nums[m] == target) {
                    pos = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                r = m - 1;
            }
        }
        return pos;
    }
    
    int end_position(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size()-1;
        int pos = -1;
        while(l <= r) {
            int m = (l + r)/2;
            if(nums[m] <= target) {
                if(nums[m] == target)
                    pos = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2);
        v[0] = starting_position(nums, target);
        v[1] = end_position(nums, target);
        return v;
    }
};