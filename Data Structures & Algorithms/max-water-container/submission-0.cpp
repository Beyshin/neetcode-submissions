class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0, high = heights.size() - 1;
        int max_area = 0;
        while(low <= high){
            int curr_area = min(heights[low], heights[high]) * (high-low);
            max_area = max(max_area, curr_area);

            if(heights[low] > heights[high]){
                high--;
            }else{
                low++;
            }
        }

        return max_area;
    }
};
