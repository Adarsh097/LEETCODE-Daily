class Solution {
public:
    int minSwaps(string s) {
        int close = 0;
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[')
                open++;
            else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }

        return (open + 1) / 2;
    }
};