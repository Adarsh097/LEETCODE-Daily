class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int>arr;
        for(int i=0;i<n;i++){
            arr.push_back(stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2)));
        }
        sort(arr.begin(),arr.end());

        int minDiff = 24*60;
        for(int i=0;i<arr.size()-1;i++){
            minDiff = min(minDiff,abs(arr[i+1]-arr[i]));
        }
        minDiff = min(minDiff,(24*60 - arr[n-1]+arr[0]));
        return minDiff;
    }
};