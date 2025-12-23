class Solution {
public:
   int minSwaps(vector<int>& A, vector<int>& F) {
       int n = A.size(), max_bad = 0, bad = 0, one_val = -1, one_freq = 1;
       unordered_map<int, int> A_frq, F_frq, bads;

       for(int i = 0; i < n; ++i) {
           A_frq[A[i]] += 1;
           F_frq[F[i]] += 1;

           if(A[i] == F[i]) {
               if(one_val != -1 && one_val != A[i])
                   one_freq = 0;
               
               one_val = A[i];
               
               bad += 1;
               max_bad = max(max_bad, ++bads[A[i]]);
           }
       }

       for(int i = 0; i < n; ++i) 
           if(A_frq[A[i]] > (n - F_frq[A[i]]))
               return -1;

       if(one_freq)
           return max_bad;
       
       return (bad + 1) / 2;
   }
};
