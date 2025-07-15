class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int m = mat.size(), n = n = mat[0].size();
     int dist = 1;
     queue<pair<int,int>>q;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({i,j});
            }else{
                mat[i][j] = -1;
            }
        }
     }
     int r[4] = {1,0,-1,0};
     int c[4] = {0,1,0,-1};
     while(!q.empty()){
        int k = q.size();
        for(int i=0;i<k;i++){
            int u = q.front().first, v = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nu = u + r[j], nv = v + c[j];
                if(nu<0 || nv < 0 || nu>=m || nv>=n || mat[nu][nv]!=-1)continue;
                mat[nu][nv] = dist;
                q.push({nu,nv});
            }
        }
        dist++;
     }   
     return mat;
    }
};