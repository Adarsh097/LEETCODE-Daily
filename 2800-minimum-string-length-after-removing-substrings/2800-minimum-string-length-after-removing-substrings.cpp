class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }else{
                if((st.top()=='A' && ch =='B') || (st.top()=='C' && ch=='D')){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};