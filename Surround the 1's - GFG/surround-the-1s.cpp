//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int cnt = 0;
                for(int dir=0;dir<8;dir++){
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj]==0){
                        cnt++;
                    }
                }
                if(cnt>0 && cnt%2==0){
                    answer++;
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends