//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int u,int n,vector<vector<int>>& graph,vector<int> &visited){
        if(visited[u]) return;
        visited[u] = 1;
        for(int v = 0;v < n ; v++){
            if(u==v) continue;
            if(graph[u][v]==0) continue;
            if(visited[v]) continue;
            dfs(v,n,graph,visited);
        }
    }
  
    int numProvinces(vector<vector<int>> graph, int n) {
        vector<int>visited(n,0);
        int comp = 0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            comp++;
            dfs(i,n,graph,visited);
        }
        return comp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends