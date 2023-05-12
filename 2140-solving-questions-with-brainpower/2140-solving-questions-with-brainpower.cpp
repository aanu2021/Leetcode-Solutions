class Solution {
public:
    
    typedef long long ll;
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<ll>dp(n,0LL);
        
        dp[n-1] = (ll)questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(i + questions[i][1] + 1 < n){
                dp[i] = max(dp[i],(ll)questions[i][0] + dp[i+questions[i][1]+1]);
            }
            else{
                dp[i] = max(dp[i],(ll)questions[i][0]);
            }
        }
        
        return dp[0];
        
    }
};