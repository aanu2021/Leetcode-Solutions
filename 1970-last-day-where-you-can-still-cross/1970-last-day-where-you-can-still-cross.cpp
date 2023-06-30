class DSU{
  
    vector<int>Parent;
    vector<int>Rank;
    
    public :
    
    DSU(int n){
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
    }
    
    int find(int x){
        if(Parent[x] == x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    bool Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Rank[lx] > Rank[ly]){
                Parent[ly] = lx;
            }
            else{
                Parent[lx] = ly;
                if(Rank[lx] == Rank[ly]) Rank[lx]++;
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isSameGroup(int x,int y){
        int lx = find(x);
        int ly = find(y);
        return lx==ly;
    }
    
};

class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
            
    int getCell(int i,int j,int m,int n){
        return ((i-1)*n) + (j-1) + 1;
    }
    
    bool isValid(vector<vector<int>>&grid,int i,int j,int m,int n){
        if(i <= 0 || j <= 0 || i > m || j > n || grid[i][j]==0) return false;
        else return true;
    }
    
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        
        int M = cells.size();
        
        reverse(cells.begin(),cells.end());
        
        DSU obj(M+2);
        
        vector<vector<int>>grid(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<M;i++){
            
            int x = cells[i][0];
            int y = cells[i][1];
            
            grid[x][y] = 1;
            
            int currCell = getCell(x,y,m,n);
            
            // cout<<currCell<<"\n";
            
            if(x==1){
                obj.Union(currCell,0);
            }
            if(x==m){
                obj.Union(currCell,M+1);
            }
            
            for(int dir=0;dir<4;dir++){
                
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(isValid(grid,nx,ny,m,n)){
                    int nbrCell = getCell(nx,ny,m,n);
                    obj.Union(currCell,nbrCell);
                }
                
            }
            
            bool isPos = obj.isSameGroup(0,M+1);
            
            if(isPos){
                return M-i-1;
            }
            
        }
        
        return 0;
        
    }
};

/*

0 -> Top Leader
1...m*n -> General Cells
m*n + 1 -> Bottom Leader

at any point of time, if top and bottom leaders are in the same group, then there is a path from atleast one of the top most cells, and atleast one of the bottom most cells.

    Top
/ / | | \ \
. . . . . .
. . . . . .
. . . . . .
. . . . . .
\ \ | | / /
   Bottom     
   
   */