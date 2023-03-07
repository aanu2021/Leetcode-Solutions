//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int u,vector<vector<int>>&graph,vector<int>&visited,vector<int>&comp){
        if(visited[u]) return;
        visited[u] = 1;
        comp.push_back(u);
        for(int v:graph[u]){
            if(visited[v]) continue;
            dfs(v,graph,visited,comp);
        }
    }
  
    int findNumberOfGoodComponent(int n, vector<vector<int>>&graph) {
        vector<int>visited(n+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            vector<int>comp;
            dfs(i,graph,visited,comp);
            int csz = comp.size();
            int flag = 1;
            for(int node:comp){
                if(graph[node].size() != (csz-1)){
                    flag = 0;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends