// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int n, vector<vector<int>>adj, int src) {
        
        vector<int>dist(n,1e8);
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<adj.size();i++){
            graph[adj[i][0]].push_back({adj[i][1],adj[i][2]});
        }
        
        dist[src]=0;
        
        queue<pair<int,int>>q;
        
        q.push({src,0});
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int node=curr.first;
            int wt=curr.second;
            
            if(dist[node]<wt){
                continue;
            }
            
            for(auto j:graph[node]){
                
                if(dist[j.first]>dist[node]+j.second){
                    dist[j.first]=dist[node]+j.second;
                    q.push({j.first,dist[j.first]});
                }
                
            }
            
        }
        
        return dist;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends