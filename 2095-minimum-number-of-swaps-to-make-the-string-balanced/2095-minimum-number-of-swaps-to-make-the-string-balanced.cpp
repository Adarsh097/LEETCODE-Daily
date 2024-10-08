class Solution {
public:
// ]][[ -> 1 swap
// ]]][[[ -> 2 swap
// ]]]][[[[ -> 2 swap
// total swaps for this -> ((total opening brackets or total closing brackets)+1)/2 
    int minSwaps(string s) {
        int n = s.size();
        stack<int>st;
        int countSwap = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '['){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop(); // to pop the complementary bracket
                }else{
                    //no complementary bracket to pop from the stack coz of reversing
                    countSwap++;
                }
            }
        }
        return (countSwap + 1)/2;
    }
};