1class Solution {
2public:
3    int beautySum(string s) {
4        int n = s.size();
5        int ans = 0;
6
7        for (int i = 0; i < n; i++) {
8            vector<int> cnt(26, 0);
9
10            for (int j = i; j < n; j++) {
11                cnt[s[j] - 'a']++;
12
13                int maxi = INT_MIN, mini = INT_MAX;
14
15                for (int k = 0; k < 26; k++) {
16                    if (cnt[k] > 0) {
17                        maxi = max(maxi, cnt[k]);
18                        mini = min(mini, cnt[k]);
19                    }
20                }
21                ans += (maxi - mini);
22            }
23        }
24        return ans;
25    }
26};
27