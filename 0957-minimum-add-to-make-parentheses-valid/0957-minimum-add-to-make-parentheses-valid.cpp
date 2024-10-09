class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0)return 0;

        stack<char>st;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }else{
                if(st.empty()){
                    ans++;
                }else{
                    st.pop();
                }
            }
        }
        return ans + st.size();
    }
};