//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int threshold) {
                     
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = min(dist[u][v],w);
            dist[v][u] = min(dist[v][u],w);
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        vector<int>reach(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j] <= threshold || dist[j][i] <= threshold){
                    reach[i]++;
                }
            }
        }
        
        int mini = *min_element(reach.begin(),reach.end());
        
        for(int i=n-1;i>=0;i--){
            if(reach[i]==mini) return i;
        }
        
        return -1;
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends