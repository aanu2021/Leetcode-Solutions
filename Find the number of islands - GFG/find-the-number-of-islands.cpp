//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands
    
    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};
    
    void dfs(vector<vector<char>>&grid,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j]=='0') return;
        grid[i][j] = '0';
        for(int dir = 0;dir < 8; dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            dfs(grid,ni,nj,m,n);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
         int m = grid.size();
         int n = grid[0].size();
         int comp = 0;
         
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j] == '0') continue;
                 comp++;
                 dfs(grid,i,j,m,n);
             }
         }
         
         return comp;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends