class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = 0; k < m; k++) {
                    for (int l = k; l <= m; l++) {
                        string temp = s.substr(i, j - i ) + t.substr(k, l - k );
                        if (isPalindrome(temp)) {
                            ans = max(ans, (j - i) + (l - k ));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
