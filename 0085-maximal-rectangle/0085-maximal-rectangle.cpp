class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>lS,rS;
        lS.push(-1);
        rS.push(n);
        vector<int>preS(n,-1);
        vector<int>nextS(n,n);
        for(int i=0;i<n;i++){
            int currEleLeft = heights[i];
            int currEleRight = heights[n-1-i];
            while(lS.top()!=-1 && currEleLeft <= heights[lS.top()]){
                lS.pop();
            }
            preS[i] = lS.top();
            lS.push(i);

            while(rS.top()!=n && currEleRight <= heights[rS.top()]){
                rS.pop();
            }
            nextS[n-i-1] = rS.top();
            rS.push(n-1-i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int currWidth = nextS[i] - preS[i]-1;
            ans = max(ans,currWidth*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        vector<int>arr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1') arr[j]++;
                else arr[j] = 0;
            }
            int area = largestRectangleArea(arr);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};