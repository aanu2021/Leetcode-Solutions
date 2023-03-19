//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int m, int n) {
        queue<pair<int,int>>q;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X'){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if(grid[x][y]=='Y') return lvl;
                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(visited[nx][ny]==0){
                            visited[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends