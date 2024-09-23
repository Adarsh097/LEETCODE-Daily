class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //initialising the array with negative index
        int hash[256];
        fill(hash,hash+256,-1);
        int maxLen = 0;
        int len = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        while(right<n){
            //check if the character is already in the substring

            if(hash[s[right]] != -1){
                if(hash[s[right]]>=left)
                left = hash[s[right]] + 1;
                cout<<"here"<<endl;
            }
            // get the maxLen
            cout<<"there"<<endl;
            len = right - left + 1;
            maxLen = max(maxLen,len);
            cout<<"left: "<<left<<"\nright: "<<right<<endl;
            cout<<"maxLen: "<<maxLen<<endl;
            hash[s[right]] = right;
            right++;

        }
        return maxLen;
    }
};