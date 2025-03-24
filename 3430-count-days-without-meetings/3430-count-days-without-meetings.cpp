class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int s = meetings[0][0], e = meetings[0][1];
        int cnt = 0;
        for(int i=1;i<n;i++){
            int ns = meetings[i][0], ne = meetings[i][1];
            if(e>=ns){
                e = max(e,ne);
            }else{
                cnt += (e-s)+1;
                s = ns;
                e = ne;
            }
        }
        cnt += (e-s+1);
        return days - cnt;
    }
};