class Solution {
public:
    bool divisorGame(int n) {
        vector<bool>dp(n+1,false);
        dp[0] = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<i;j++){
                if(i%j==0){
                    if(dp[i-j]==false){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};