class Solution {
public:
    
    int ans=0;
    
    void func(vector<vector<int>>&grid,int i,int j,int zero){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1){
            return;
        }
        
        if(grid[i][j]==2){
            
            if(zero==-1){
                ans++;
            }
            
            return;
            
        }
        
        
        zero--;
        
        int temp=grid[i][j];
        
        grid[i][j]=-1;
        
        func(grid,i+1,j,zero);
        func(grid,i-1,j,zero);
        func(grid,i,j+1,zero);
        func(grid,i,j-1,zero);
        
        zero++;
        
        grid[i][j]=temp;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int zero=0;
        
        int x=-1,y=-1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zero++;
                }
                else if(grid[i][j]==1){
                    
                    x=i;
                    y=j;
                    
                }
            }
        }
        
        func(grid,x,y,zero);
        
        return ans;
        
    }
};