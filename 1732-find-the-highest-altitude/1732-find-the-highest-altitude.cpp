class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0;
        int n = gain.size();
        int height = 0;
        for(int i=0;i<n;i++){
            height += gain[i];
            maxHeight = max(maxHeight,height);
        }
        return maxHeight;
    }
};