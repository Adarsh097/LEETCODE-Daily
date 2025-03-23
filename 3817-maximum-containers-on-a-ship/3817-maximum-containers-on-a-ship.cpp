class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int maxContainer = maxWeight/w;
        return (n*n > maxContainer)?maxContainer : n*n;
    }
};