class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& matrix) {
         int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n));
        
        int dx[8]={0,0,1,-1,1,1,-1,-1};
        int dy[8]={1,-1,0,0,1,-1,1,-1};
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                int count=1;
                
                int val=matrix[i][j];
                
                for(int k=0;k<8;k++){
                    
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && y>=0 && x<m && y<n){
                        count++;
                        val+=matrix[x][y];
                    }
                    
                }
                
                dp[i][j]=val/count;
                
            }
            
        }
        
        return dp;
    }
};