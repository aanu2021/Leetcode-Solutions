class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<n;++i){
            
            int x=0,y=i;
            
            vector<int>v;
            
            while(x<m && y<n){
                v.push_back(grid[x][y]);
                x++;
                y++;
            }
            
            x=0,y=i;
            
            sort(v.rbegin(),v.rend());
            
            while(x<m && y<n){
                grid[x][y]=v.back();
                v.pop_back();
                x++;
                y++;
            }
            
        }
        
        
        for(int i=1;i<m;++i){
            
            int x=i,y=0;
            
            vector<int>v;
            
            while(x<m && y<n){
                v.push_back(grid[x][y]);
                x++;
                y++;
            }
            
            x=i,y=0;
            
            sort(v.rbegin(),v.rend());
            
            while(x<m && y<n){
                grid[x][y]=v.back();
                v.pop_back();
                x++;
                y++;
            }
            
        }
        
        return grid;
        
    }
};