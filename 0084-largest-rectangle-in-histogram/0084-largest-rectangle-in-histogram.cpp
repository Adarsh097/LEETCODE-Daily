class Solution {
public:
    vector<int>preSolve(vector<int>&arr){
        stack<int>st;
        int n = arr.size();
        st.push(-1);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
       vector<int>nextSolve(vector<int>&arr){
        stack<int>st;
        int n = arr.size();
        st.push(-1);
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top()==-1?n:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>prevSmaller = preSolve(heights);
        vector<int>nextSmaller = nextSolve(heights);

        int ans = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int currHeight = heights[i];
            
            int l = prevSmaller[i];
            
            int r = nextSmaller[i];
            
            
            ans = max(ans,currHeight*(r-l-1));
        }
        return ans;
    }
};