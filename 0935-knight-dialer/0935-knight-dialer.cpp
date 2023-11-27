class Solution {
public:
    
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    
    int knightDialer(int n) {
        
        if(n == 1) return 10;
        
        int grid[4][3];
        int c = 1;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) grid[i][j] = c++;
        }
        grid[3][0] = -1;
        grid[3][1] = 0;
        grid[3][2] = -1;
        
        int dx[8] = {-2,-2,-1,-1,1,1,2,2};
        int dy[8] = {1,-1,2,-2,2,-2,1,-1};
        
        int M = 4;
        int N = 3;
        
        vector<vector<int>>prev(M,vector<int>(N,0));
        vector<vector<int>>curr(M,vector<int>(N,0));
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] != -1) prev[i][j] = 1;
            }
        }
        
        for(int turn=2;turn<=n;turn++){
            
            // Actual calculation...
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j] == -1) continue;
                    ll ways = 0LL;
                    for(int dir=0;dir<8;dir++){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if(ni >= 0 && nj >= 0 && ni < M && nj < N){
                            if(grid[ni][nj] != -1){
                                ways += prev[ni][nj];
                                ways %= MOD;
                            }
                        }
                    }
                    curr[i][j] = (int)ways;
                }
            }
            
            // updating and reinitializing values...
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    prev[i][j] = curr[i][j];
                    curr[i][j] = 0;
                }
            }
            
        }
        
        ll ways = 0LL;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                ways += prev[i][j];
                ways %= MOD;
            }
        }
        
        return (int)ways;
        
    }
};