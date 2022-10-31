class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>rows(m+n,-1);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=j-i+m;
                if(rows[idx]==-1){
                    rows[idx]=grid[i][j];
                    continue;
                }else{
                    if(rows[idx]!=grid[i][j]){
                        return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};