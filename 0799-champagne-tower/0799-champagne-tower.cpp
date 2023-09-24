class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        vector<vector<double>>dp(r+1,vector<double>(r+1,0.0));
        dp[0][0] = (double)poured;
        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                double curr = dp[i][j] - 1;
                if(curr > 0){
                    dp[i+1][j] += (curr/2.0);
                    dp[i+1][j+1] += (curr/2.0);
                }
            }
        }
        return min(1.0,dp[r][c]);
    }
};