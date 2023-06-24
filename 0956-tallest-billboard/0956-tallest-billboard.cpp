class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        
        int MAX = 10001;
        
        vector<vector<bool>>dp(n+1,vector<bool>(MAX,false));
        vector<vector<int>>mx(n+1,vector<int>(MAX,0));
        
        // dp[i][j] -> represents is it possible to achieve sum of j-5000 from the first i numbers
        
        dp[0][5000] = true;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<MAX;j++){
                if(j - rods[i] >= 0 && dp[i][j-rods[i]]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j], mx[i][j-rods[i]] + rods[i]);
                }
                if(j + rods[i] < MAX && dp[i][j+rods[i]]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j], mx[i][j+rods[i]]);
                }
                if(dp[i][j]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j], mx[i][j]);
                }
            }
        }
        
        return mx[n][5000];
        
    }
};