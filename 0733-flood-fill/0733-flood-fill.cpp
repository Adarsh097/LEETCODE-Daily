class Solution {
public:
    //4-directionally travel
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
     vector<vector<int>>arr;
     void dfs(int sr,int sc,int color,int initialColor){
        arr[sr][sc] = color;
        for(int i=0;i<4;i++){
            int nr = sr + row[i];
            int nc = sc + col[i];
            if(nr>=0 && nr<arr.size() && nc>=0 && nc<arr[0].size() && arr[nr][nc]==initialColor){
                dfs(nr,nc,color,initialColor);
            }
        }
        return;
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor == color)return image;
        arr = image;
        dfs(sr,sc,color,initialColor);
        return arr;

    }
};