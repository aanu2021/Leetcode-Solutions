//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<bool>>visited(m,vector<bool>(n,false));
	    queue<pair<int,int>>q;
	    vector<vector<int>>dist(m,vector<int>(n,1e9));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]){
	                dist[i][j] = 0;
	                visited[i][j] = true;
	                q.push({i,j});
	            }
	        }
	    }
	    int dx[4] = {0,0,1,-1};
	    int dy[4] = {1,-1,0,0};
	    int lvl = 0;
	    while(!q.empty()){
	        int sz = q.size();
	        while(sz--){
	            auto curr = q.front();
	            q.pop();
	            int i = curr.first;
	            int j = curr.second;
	            dist[i][j] = lvl;
	            for(int dir = 0;dir < 4;dir++){
	                int ni = i + dx[dir];
	                int nj = j + dy[dir];
	                if(ni>=0 && ni<m && nj>=0 && nj<n){
	                    if(visited[ni][nj]) continue;
	                    visited[ni][nj] = true;
	                    q.push({ni,nj});
	                }
	            }
	        }
	        lvl++;
	    }
	    return dist;
	}
};

/*

0 1 1 0
1 1 0 0
0 0 1 1

i 0 0 i
0 0 i i 
i i 0 0

*/


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends