//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node{
  
   int node;
   int distance;
   int stop;
    
};

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        k++;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        queue<Node>q;
        q.push({src,0,0});
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front(); q.pop();
                int node = curr.node;
                int distance = curr.distance;
                int stop = curr.stop;
                if(lvl == k) continue;
                for(auto nbrs:graph[node]){
                    int nbr = nbrs.first;
                    int weight = nbrs.second;
                    if(dist[nbr] > distance + weight){
                        dist[nbr] = distance + weight;
                        q.push({nbr,dist[nbr],stop+1});
                    }
                }
            }
            lvl++;
        }
        if(dist[dst] >= 1e9) return -1;
        else return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends