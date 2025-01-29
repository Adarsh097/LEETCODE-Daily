class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)return 0;
        int ans = 0;
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        int temp1 = 0, temp2 = 0;
        for(int i=0;i<n;i++){
            temp1 = max(height[i],temp1);
            leftMax[i] = temp1;
            temp2 = max(height[n-1-i],temp2);
            rightMax[n-1-i] = temp2;
        }
        for(int i=1;i<n-1;i++){
            int currHeight = height[i];
            
            int waterCollected = min(leftMax[i],rightMax[i]) - currHeight;
            
            if(waterCollected > 0){
                ans += waterCollected;
            }
        }
        return ans;
    }
};