class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        
        vector<vector<double>>dp(r+1,vector<double>(r+1,0.0));
        
        dp[0][0]=(double)poured;
        
        for(int i=0;i<r;i++){
            
            for(int j=0;j<=i;j++){
                
                double curr=(dp[i][j]-1);
                
                if(curr>0){
                    
                    dp[i+1][j]+=(curr*1.0/2);
                    dp[i+1][j+1]+=(curr*1.0/2);
                    
                }
                
            }
            
        }
        
        return min(dp[r][c],1.0);
        
    }
};