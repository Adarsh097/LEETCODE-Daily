class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
   
        int startColor = image[sr][sc];
            if(startColor == color)return image;
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        int row[4] = {1,0,-1,0};
        int col[4] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n &&image[nr][nc]==startColor){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};