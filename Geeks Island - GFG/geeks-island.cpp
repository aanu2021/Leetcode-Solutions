//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<bool>>&vis){
        vis[i][j] = true;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                if(grid[ni][nj] >= grid[i][j] && vis[ni][nj]==false){
                    dfs(grid,ni,nj,m,n,vis);
                }
            }
        }
    }

    int water_flow(vector<vector<int>> &grid,int m,int n){
    
       vector<vector<bool>>vis1(m,vector<bool>(n,false));
       vector<vector<bool>>vis2(m,vector<bool>(n,false));
       
       for(int i=0;i<n;i++){
           dfs(grid,0,i,m,n,vis1);
       }
       for(int i=0;i<m;i++){
           dfs(grid,i,0,m,n,vis1);
       }
       
       for(int i=0;i<n;i++){
           dfs(grid,m-1,i,m,n,vis2);
       }
       for(int i=0;i<m;i++){
           dfs(grid,i,n-1,m,n,vis2);
       }
       
       int answer = 0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(vis1[i][j] && vis2[i][j]) answer++;
           }
       }
       
       return answer;
    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends