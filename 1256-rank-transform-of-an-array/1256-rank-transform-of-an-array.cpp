
class Solution {
   
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>v;
        int n = arr.size();
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[v[i].second] = 1;
            }else{
                if(v[i].first == v[i-1].first){
                    ans[v[i].second] = ans[v[i-1].second];
                }else{
                    ans[v[i].second] = ans[v[i-1].second] + 1;
                }
            }
        }
        return ans;

    }
};