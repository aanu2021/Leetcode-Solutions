//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCycle(int u,vector<int>adj[],vector<int>&vis,vector<int>&cvis){
        vis[u] = 1;
        cvis[u] = 1;
        for(int v:adj[u]){
            if(vis[v]){
                if(cvis[v]){
                    return true;
                }
            }
            else{
                bool flag = isCycle(v,adj,vis,cvis);
                if(flag) return true;
            }
        }
        cvis[u] = 0;
        return false;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int>visited(n,0);
        vector<int>cvisited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(isCycle(i,adj,visited,cvisited)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends