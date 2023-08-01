//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int m, int n, vector<vector<int>> grid, int x, int y) {
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0] = true;
        int lvl = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front(); q.pop();
                int i = curr.first;
                int j = curr.second;
                if(i==x && j==y) return lvl;
                for(int dir=0;dir<4;dir++){
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                        if(visited[ni][nj] || grid[ni][nj]==0) continue;
                        visited[ni][nj] = true;
                        q.push({ni,nj});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends