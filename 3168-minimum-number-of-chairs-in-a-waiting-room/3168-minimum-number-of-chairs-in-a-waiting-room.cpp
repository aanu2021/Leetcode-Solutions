class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length();
        int currSum = 0;
        int maxSum = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'E') currSum++;
            else currSum--;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};