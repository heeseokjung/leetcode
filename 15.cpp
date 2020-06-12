class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        int size = (int)nums.size();
        for(int i = 0; i < size; ++i) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = size-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ret.push_back(tmp);
                    j++; k--;
                    
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                } else if(sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return ret;
    }
};