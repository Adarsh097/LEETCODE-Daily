class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        for(int i=1;i<n-1;i++){
            int leftMax = height[i];
            int rightMax = height[i];
            for(int j=0; j<i ; j++){
                leftMax = max(leftMax,height[j]);
            }
            for(int j=i+1;j<n;j++){
                rightMax = max(rightMax,height[j]);
            }
            water += min(leftMax,rightMax) - height[i];
        }
        return water;
    }
};