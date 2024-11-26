class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0;
        int ed = height.size()-1;
        int maxiArea = 0;
        while(st<ed){
            maxiArea = max(maxiArea,(min(height[ed],height[st])*(ed-st)));
            if(height[st]<height[ed]){
                st++;
            }else{
                ed--;
            }
        }
        return maxiArea;
    }
};