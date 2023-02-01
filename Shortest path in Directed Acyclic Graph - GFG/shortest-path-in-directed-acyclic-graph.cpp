//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     vector<int>topoSorting(int n,vector<vector<pair<int,int>>>&graph){
         vector<int>indegree(n,0);
         for(int i=0;i<n;i++){
             for(auto nbrs:graph[i]){
                 indegree[nbrs.first]++;
             }
         }
         queue<int>q;
         for(int i=0;i<n;i++){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         vector<int>topo;
         while(!q.empty()){
             int node = q.front(); q.pop();
             topo.push_back(node);
             for(auto nbrs:graph[node]){
                 int nbr = nbrs.first;
                 indegree[nbr]--;
                 if(indegree[nbr]==0){
                     q.push(nbr);
                 }
             }
         }
         return topo;
     }
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>vec = topoSorting(n,graph);
        
        vector<int>dist(n,1e9);
        dist[0] = 0;
        
        for(int i=0;i<vec.size();i++){
            int node = vec[i];
            for(auto nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                dist[nbr] = min(dist[nbr],dist[node] + edgeWt);
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] >= 1e9) dist[i] = -1;
        }
        return dist;
        
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends