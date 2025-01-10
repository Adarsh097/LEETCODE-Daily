class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxiScore = 0;
        int leftSum  = 0, rightSum = 0, i = 0,j=cardPoints.size()-1;
       
        while(i <k){
            leftSum += cardPoints[i++];
        }
        maxiScore = max(maxiScore,leftSum + rightSum);
        i--;
        while(i>=0){
            leftSum -= cardPoints[i];
            i--;
            rightSum += cardPoints[j];
            j--;
            maxiScore = max(maxiScore,leftSum + rightSum);
        }
        return maxiScore;
    }
};