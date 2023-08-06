//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(int u,vector<int>graph[],vector<bool>&vis,vector<bool>&cvis){
        vis[u] = true;
        cvis[u] = true;
        for(int v : graph[u]){
            if(vis[v] == false){
                bool flag = checkCycle(v,graph,vis,cvis);
                if(flag){
                    return true;
                }
            }
            else{
                if(cvis[v]){
                    return true;
                }
            }
        }
        cvis[u] = false;
        return false;
    }
    
    bool isCyclic(int n, vector<int> graph[]) {
        vector<bool>vis(n,false);
        vector<bool>cvis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            if(checkCycle(i,graph,vis,cvis)){
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