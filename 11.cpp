class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = (int)height.size();
        int i = 0, j = size-1, max_area = 0;
        while(i < j) {
            if(max_area < (j-i)*min(height[i], height[j]))
                max_area = (j-i)*min(height[i], height[j]);
            if(height[i] <= height[j])
                i++;
            else
                j--;
        }
        
        return max_area;
    }
};