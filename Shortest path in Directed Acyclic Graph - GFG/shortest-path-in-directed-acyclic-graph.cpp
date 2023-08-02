//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>dist(N,1e9);
        dist[0] = 0;
        vector<vector<pair<int,int>>>graph(N);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int node = curr.second;
            int wt = curr.first;
            if(dist[node] != wt) continue;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                if(dist[nbr] > dist[node] + edgeWt){
                    dist[nbr] = dist[node] + edgeWt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i] >= 1e9){
                dist[i] = -1;
            }
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