class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>temp;
        for(auto &p : firstList){
            temp.push_back({p[0],1});
            temp.push_back({p[1],-1});
        }
         for(auto &p : secondList){
            temp.push_back({p[0],1});
            temp.push_back({p[1],-1});
        }
        sort(temp.begin(),temp.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }else{
                return a[0]<b[0];
            }
        });
        vector<vector<int>>ans;
        int s = 0;
        int cnt = 0;
        for(int i=0;i<temp.size();i++){
            cnt += temp[i][1];
            if(cnt==2)s = temp[i][0];
            if(i+1<temp.size()){
                if(temp[i][0]==temp[i+1][0] && temp[i][1]!=temp[i+1][1]){
                    ans.push_back({temp[i][0],temp[i][0]});
                }
                if(cnt==2 && temp[i+1][1]==-1){
                ans.push_back({s,temp[i+1][0]});
                i++;
                cnt--;
                }
            }
        }
        return ans;

    }
};