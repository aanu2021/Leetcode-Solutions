//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<int>dijkstra(int src,vector<vector<pair<int,int>>>&graph,int n){
        vector<int>dist(n+1,1e9 + 1e5);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(dist[node] > wt) continue;
            for(auto &nbrs:graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                if(dist[nbr] > dist[node] + edgeWt){
                    dist[nbr] = dist[node] + edgeWt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        return dist;
    }
  
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<int>dist1 = dijkstra(a,graph,n);
        vector<int>dist2 = dijkstra(b,graph,n);
        int minCost = INT_MAX;
        if(dist1[b] <= 1e9){
            minCost = min(minCost,dist1[b]);
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][3];
            if(dist1[u] <= 1e9 && dist2[v] <= 1e9){
                minCost = min(minCost,dist1[u] + w + dist2[v]);
            }
            if(dist1[v] <= 1e9 && dist2[u] <= 1e9){
                minCost = min(minCost,dist1[v] + w + dist2[u]);
            }
        }
        if(minCost == INT_MAX) return -1;
        else return minCost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends