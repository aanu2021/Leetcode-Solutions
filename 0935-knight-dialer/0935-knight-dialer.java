class Solution {
    
    final long MOD = 1000000007;
    
    public boolean isPossible(int x,int y,int grid[][],int M,int N){
        if(x >= 0 && y >= 0 && x < M && y < N && grid[x][y] != -1) return true;
        else return false;
    }
    
    public int knightDialer(int n) {
        
        if(n == 1) return 10;
        
        int M = 4;
        int N = 3;
        
        int grid[][] = new int[M][N];
        int prev[][] = new int[M][N];
        int curr[][] = new int[M][N];
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                prev[i][j] = 0;
                curr[i][j] = 0;
            }
        }
        
        int counter = 1;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) grid[i][j] = counter++;
        }
        grid[3][0] = -1;
        grid[3][1] = 0;
        grid[3][2] = -1;
        
        int dx[] = {-2,-2,-1,-1,1,1,2,2};
        int dy[] = {1,-1,2,-2,2,-2,1,-1};
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == -1) continue;
                prev[i][j] = 1;
            }
        }
        
        for(int turn=2;turn<=n;turn++){
            
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j] == -1) continue;
                    long ways = 0L;
                    for(int dir=0;dir<8;dir++){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if(isPossible(ni,nj,grid,M,N) == true){
                            ways += prev[ni][nj];
                            ways %= MOD;
                        }
                    }
                    curr[i][j] = (int)ways;
                }
            }
            
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    prev[i][j] = curr[i][j];
                    curr[i][j] = 0;
                }
            }
            
        }
        
        long ways = 0L;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                ways += prev[i][j];
                ways %= MOD;
            }
        }
        
        return (int)ways;
        
    }
}