//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        for(int dir=0;dir<4;dir++){
            int ni = i+dx[dir];
            int nj = j+dy[dir];
            dfs(grid,ni,nj,m,n);
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0,m,n);
            }
            if(grid[i][n-1]==1){
                dfs(grid,i,n-1,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i,m,n);
            }
            if(grid[m-1][i]==1){
                dfs(grid,m-1,i,m,n);
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans += grid[i][j];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends