//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkCycle(int u,int p,vector<int>graph[],vector<bool>&visited){
        visited[u] = true;
        for(int v:graph[u]){
            if(v==p) continue;
            if(visited[v]) return true;
            bool flag = checkCycle(v,u,graph,visited);
            if(flag) return true;
        }
        return false;
    }
    
    bool isCycle(int n, vector<int> graph[]) {
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(checkCycle(i,-1,graph,visited)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends