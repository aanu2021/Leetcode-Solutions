//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        
        vector<int>dist(n,1e9);
        vector<bool>visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            int currwt = curr.first;
            if(visited[node]) continue;
            visited[node] = true;
            dist[node] = currwt;
            for(auto nbrs:adj[node]){
                int v = nbrs[0];
                int edge_wt = nbrs[1];
                if(visited[v]) continue;
                if(dist[v] > dist[node] + edge_wt){
                    dist[v] = dist[node] + edge_wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends