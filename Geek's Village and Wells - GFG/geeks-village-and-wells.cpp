//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int m,int n,vector<vector<char>> &grid){
       
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='W'){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(grid[nx][ny]=='N') continue;
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='H'){
                    if(dist[i][j] >= 1e9) dist[i][j] = -1;
                    else dist[i][j] *= 2;
                }
                else{
                    dist[i][j] = 0;
                }
            }
        }
        return dist;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends