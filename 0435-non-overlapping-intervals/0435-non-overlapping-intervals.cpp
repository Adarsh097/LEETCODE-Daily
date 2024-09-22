class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        int s = intervals[0][0];
        int e = intervals[0][1];
        int ans = 0;
        int i = 1;
        while(i<n){
            if(e > intervals[i][0]){
                ans++;
                if(intervals[i][1] < e){
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