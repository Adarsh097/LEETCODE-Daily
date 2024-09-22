class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        int i=1;
        int ans = 0;
        while(i<n){
            if(e > intervals[i][0]){
                ans++;
                if(e > intervals[i][1]){
                    s = intervals[i][0];
                    e = intervals[i][1];
                }
            }else{
                 s = intervals[i][0];
                 e = intervals[i][1];
            }
            i++;
        }
        return ans;
    }
};