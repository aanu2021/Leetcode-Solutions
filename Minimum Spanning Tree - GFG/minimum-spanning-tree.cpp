//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
  
  public:
  
  vector<int>Parent;
  vector<int>Rank;
  
  DSU(int n){
      Parent.resize(n);
      Rank.resize(n);
      for(int i=0;i<n;i++){
          Parent[i] = i;
          Rank[i] = 1;
      }
  }
  
  int find(int x){
      if(Parent[x]==x) return x;
      return Parent[x] = find(Parent[x]);
  }
  
  void Union(int x,int y){
      int lx = find(x);
      int ly = find(y);
      if(lx != ly){
          if(Rank[lx] < Rank[ly]){
              Parent[lx] = ly;
          }
          else{
              Parent[ly] = lx;
              if(Rank[lx] == Rank[ly]){
                  Rank[lx]++;
              }
          }
      }
  }
    
};


class Solution
{
	public:
	
	bool static comp(const vector<int>&x,const vector<int>&y){
	    return x[2] < y[2];
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(auto &nbrs : adj[i]){
                int j = nbrs[0];
                int edgeWt = nbrs[1];
                if(i < j) edges.push_back({i,j,edgeWt});
            }
        }
        
        DSU obj(n);
        sort(edges.begin(),edges.end(),comp);
        
        int sumEdgeWt = 0;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if(obj.find(u) == obj.find(v)) continue;
            obj.Union(u,v);
            sumEdgeWt += wt;
        }
        
        return sumEdgeWt;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends