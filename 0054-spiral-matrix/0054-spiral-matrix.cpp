class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr = 0;
        int sc = 0;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;
        vector<int>ans;

        while(sr<=er && sc<=ec){
            for(int i=sc;i<=ec;i++){
                ans.push_back(matrix[sr][i]);
            }
            sr++;


            for(int j=sr;j<=er;j++){
                ans.push_back(matrix[j][ec]);
            }
            ec--;

            // last row
            if(sr<=er){
                for(int i=ec;i>=sc;i--){
                    ans.push_back(matrix[er][i]);
                }
                 er--;
            }
            if(sc<=ec){
                for(int j=er;j>=sr;j--){
                    ans.push_back(matrix[j][sc]);
                }
                sc++;
            }


        }
        return ans;
    }
};