//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<char>>&grid,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 'O') return;
        grid[i][j] = 'Z';
        for(int dir = 0;dir < 4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            dfs(grid,ni,nj,m,n);
        }
    }

    vector<vector<char>> fill(int m, int n, vector<vector<char>> grid)
    {
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                dfs(grid,i,0,m,n);
            }
            if(grid[i][n-1]=='O'){
                dfs(grid,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i]=='O'){
                dfs(grid,0,i,m,n);
            }
            if(grid[m-1][i]=='O'){
                dfs(grid,m-1,i,m,n);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O'){
                    grid[i][j] = 'X';
                }
                if(grid[i][j]=='Z'){
                    grid[i][j] = 'O';
                }
            }
        }
        
        return grid;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends