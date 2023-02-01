//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>graph(n);
        vector<bool>visited(n,false);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(n,1e9);
        dist[0] = 0;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(visited[node]) continue;
            visited[node] = true;
            for(auto nbrs:graph[node]){
               int nbr = nbrs.first;
               int edge_wt = nbrs.second;
               if(visited[nbr]) continue;
               if(dist[nbr] > dist[node] + edge_wt){
                   dist[nbr] = dist[node] + edge_wt;
                   pq.push({dist[nbr],nbr});
               }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]>=1e9) dist[i] = -1;
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