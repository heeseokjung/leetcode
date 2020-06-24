class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = (int)nums.size();
        int l = 0, r = size-1;
        
        int pos = -1;
        while(l <= r) {
            int m = (l + r)/2;
            if(target == nums[m]) {
                pos = m;
                break;
            }
            if(nums[l] <= nums[m]) { 
                if(nums[l] <= target && nums[m] >= target)
                    r = m - 1;
                else
                    l = m + 1;
            } else {              
                if(nums[m] <= target && nums[r] >= target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return pos;
    }
};