//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Pair{
  
   int x;
   int y;
   int wt;
    
};

struct comp{
  
  bool operator()(const Pair&x,const Pair&y){
      return x.wt > y.wt;
  }
    
};

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<Pair,vector<Pair>,comp>pq;
        pq.push({0,0,0});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int x = curr.x;
            int y = curr.y;
            int wt = curr.wt;
            if(visited[x][y]) continue;
            if(x == m-1 && y == n-1) return wt;
            visited[x][y] = true;
            for(int dir = 0;dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(visited[nx][ny]) continue;
                    pq.push({nx,ny,max(wt,abs(grid[nx][ny]-grid[x][y]))});
                }
            }
        }
        return -1;
    }
};

/*

1 2 2
3 8 2
5 3 5

*/


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends