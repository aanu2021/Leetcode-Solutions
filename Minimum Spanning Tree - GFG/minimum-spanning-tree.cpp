// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	struct comp{
	  
	  bool operator()(const pair<int,int>&x,const pair<int,int>&y){
	      return x.second > y.second;
	  }  
	    
	};
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        vector<bool>visited(n,false);
        
        pq.push({0,0});
        
        int ans=0;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int node=curr.first;
            int wt=curr.second;
            
            if(visited[node]==true){
                continue;
            }
            
            visited[node]=true;
            
            ans+=wt;
            
            for(auto j:adj[node]){
                
                if(visited[j[0]]==true){
                    continue;
                }
                
                pq.push({j[0],j[1]});
                
            }
            
        }
        
        return ans;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends