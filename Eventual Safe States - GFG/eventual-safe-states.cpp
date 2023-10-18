//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[i]++;
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>answer;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            answer.push_back(node);
            for(int &nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends