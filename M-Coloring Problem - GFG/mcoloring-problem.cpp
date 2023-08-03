//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int u,vector<vector<int>>&graph,vector<int>&visited,int color){
        for(int v:graph[u]){
            if(visited[v] == color){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int u,int n,vector<vector<int>>&graph,vector<int>&visited,int m){
        if(u==n) return true;
        for(int col=1;col<=m;col++){
            if(isSafe(u,graph,visited,col)){
                visited[u] = col;
                if(dfs(u+1,n,graph,visited,m)){
                    return true;
                }
                visited[u] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool adj[101][101], int m, int n) {
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<int>visited(n,0);
        
        return dfs(0,n,graph,visited,m);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends