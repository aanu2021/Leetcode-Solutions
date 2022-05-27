class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        
        vector<vector<double>>dp(n,vector<double>(n,0.0));
        
        dp[r][c]=1.0;
        
        double sum=0.0;
        
        int dx[8]={1,1,-1,-1,2,2,-2,-2};
        int dy[8]={2,-2,2,-2,1,-1,1,-1};
        
        while(k--){
            
            vector<vector<double>>dp2(n,vector<double>(n,0.0));
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    if(dp[i][j]!=0){
                        
                        for(int dir=0;dir<8;dir++){
                            
                            int x=i+dx[dir];
                            int y=j+dy[dir];
                            
                            if(x>=0 && x<n && y>=0 && y<n){
                                
                                dp2[x][y]+=((dp[i][j]*1.0)/8);
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
             dp=dp2;
            
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                sum+=dp[i][j];
                
            }
            
        }
        
        return sum;
        
    }
};