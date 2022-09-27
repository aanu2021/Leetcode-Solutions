class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n=board.size();
        
        vector<vector<int>>grid(n,vector<int>(n,-1));
        
        for(int i=0;i<n;++i){
            
            for(int j=0;j<n;++j){
                
                grid[i][j]=board[i][j]-'0';
                
                if(board[i][j]=='X') grid[i][j] = -1;
                
            }
            
        }
        
        grid[0][0]=0;
        grid[n-1][n-1]=0;
        
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<grid[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
        
        vector<vector<int>>maxval(n,vector<int>(n,-1));
        
        vector<vector<ll>>roads(n,vector<ll>(n,0LL));
        
        maxval[n-1][n-1]=0;
        roads[n-1][n-1]=1LL;
        
        for(int i=n-2;i>=0;i--){
            
            if(grid[i][n-1]==-1){
                
                maxval[i][n-1]=-1;
                roads[i][n-1]=0;
                break;
                
            }
            
            else{
                
                maxval[i][n-1]=maxval[i+1][n-1]+grid[i][n-1];
                roads[i][n-1]=1LL;
                
            }
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(grid[n-1][i]==-1){
                
                maxval[n-1][i]=-1;
                roads[n-1][i]=0;
                break;
                
            }
            
            else{
                
                maxval[n-1][i]=maxval[n-1][i+1]+grid[n-1][i];
                roads[n-1][i]=1LL;
                
            }
            
        }
        
        int dx[3] = {1,0,1};
        int dy[3] = {0,1,1};
        
        for(int i=n-2;i>=0;i--){
            
            for(int j=n-2;j>=0;j--){
                
                if(grid[i][j]==-1){
                    
                    maxval[i][j] = -1;
                    roads[i][j] = 0LL;
                    continue;
                    
                }
                
                for(int dir=0;dir<3;dir++){
                    
                    int ni=i+dx[dir];
                    int nj=j+dy[dir];
                    
                    if(maxval[ni][nj] == -1){
                        continue;
                    }
                    
                    if(maxval[i][j] < grid[i][j] + maxval[ni][nj]){
                        
                        maxval[i][j] = grid[i][j] + maxval[ni][nj];
                        roads[i][j] = roads[ni][nj];
                        
                    }
                    
                    else if(maxval[i][j] == grid[i][j] + maxval[ni][nj]){
                        
                        roads[i][j] = add(roads[i][j],roads[ni][nj]);
                        
                    }
                    
                }
                
            }
            
        }
        
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<maxval[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
//         cout<<"\n";
        
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 cout<<roads[i][j]<<" ";
//             }cout<<"\n";
//         }
        
        return {max(0,maxval[0][0]),(int)roads[0][0]};
        
    }
};