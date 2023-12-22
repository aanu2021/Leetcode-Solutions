class Solution {
public:
    int maxScore(string s) {
        int leftOne = 0, leftZero = 0, rightOne = 0, rightZero = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '0') rightZero++;
            else rightOne++;
        }
        int maxScore = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '0'){
                leftZero++;
                rightZero--;
            }
            else{
                leftOne++;
                rightOne--;
            }
            maxScore = max(maxScore, leftZero + rightOne);
        }
        return maxScore;
    }
};