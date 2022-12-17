//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isCycle(int node,vector<int>graph[],vector<bool>&visited,vector<bool>&timer){
        visited[node] = true;
        timer[node] = true;
        
        for(int nbr:graph[node]){
            if(timer[nbr]) return true;
            if(visited[nbr]) continue;
            bool flag = isCycle(nbr,graph,visited,timer);
            if(flag) return true;
        }
        
        timer[node] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> graph[]) {
        vector<bool>visited(n,false);
        vector<bool>timer(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(isCycle(i,graph,visited,timer)) return true;
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