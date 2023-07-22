class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        
        vector<vector<double>>dp(n,vector<double>(n,0.0));
        
        int dx[8] = {2,2,1,1,-2,-2,-1,-1};
        int dy[8] = {1,-1,2,-2,1,-1,2,-2};
        
        dp[row][col] = 1.0;
        
        while(k--){
            
            vector<vector<double>>dp2(n,vector<double>(n,0.0));
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][j]){
                        for(int dir=0;dir<8;dir++){
                            int ni = i + dx[dir];
                            int nj = j + dy[dir];
                            if(ni >= 0 && ni < n && nj >= 0 && nj < n){
                                dp2[ni][nj] += ((dp[i][j]*1.0)/8);
                            }
                        }
                    }
                }
            }
            
            dp = dp2;
            
        }
        
        double sum = 0.0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += dp[i][j];
            }
        }
        
        return sum;
        
    }
};

