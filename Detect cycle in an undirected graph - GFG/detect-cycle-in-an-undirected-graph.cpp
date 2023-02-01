//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCyclicComp(int src,vector<bool>&visited,vector<int> graph[]){
        
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int node = curr.first;
                int par = curr.second;
                for(int nbr:graph[node]){
                    if(nbr == par) continue;
                    if(visited[nbr]) return true;
                    visited[nbr] = true;
                    q.push({nbr,node});
                }
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int n, vector<int> graph[]) {
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(isCyclicComp(i,visited,graph)) return true;
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