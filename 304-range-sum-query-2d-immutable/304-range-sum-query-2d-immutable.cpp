class NumMatrix {
public:
    
    vector<vector<int>>dp;
    
    NumMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+grid[i-1][j-1]-dp[i-1][j-1];
                
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;
        col1++;
        row2++;
        col2++;
        
        int sum = dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
        
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */