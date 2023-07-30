//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        visited[0] = 1;
        queue<int>q;
        q.push(0);
        vector<int>answer;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
               int node = q.front(); q.pop();
               answer.push_back(node);
               for(int &nbr : adj[node]){
                   if(visited[nbr]) continue;
                   visited[nbr] = 1;
                   q.push(nbr);
               }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends