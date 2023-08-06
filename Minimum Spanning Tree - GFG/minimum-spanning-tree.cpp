//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
   
   private:
   vector<int>Parent;
   vector<int>Rank;
   
   public:
   DSU(int n){
       Parent.resize(n);
       Rank.resize(n);
       for(int i=0;i<n;i++){
           Parent[i] = i;
           Rank[i] = 1;
       }
   }
   int find(int x){
       if(Parent[x] == x) return x;
       return Parent[x] = find(Parent[x]);
   }
   bool Union(int x,int y){
       int lx = find(x);
       int ly = find(y);
       if(lx != ly){
           if(Rank[lx] > Rank[ly]){
               Parent[ly] = lx;
           }
           else{
               Parent[lx] = ly;
               if(Rank[lx] == Rank[ly]){
                   Rank[lx]++;
               }
           }
           return true;
       }
       else{
           return false;
       }
   }
   
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> graph[])
    {
        vector<vector<int>>edges;
        for(int node=0;node<n;node++){
            for(auto &nbrs : graph[node]){
                int nbr = nbrs[0];
                int edgeWt = nbrs[1];
                edges.push_back({edgeWt,node,nbr});
            }
        }
        sort(edges.begin(),edges.end());
        DSU obj(n);
        int sum = 0;
        for(int i=0;i<edges.size();i++){
            int edgeWt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if(obj.Union(u,v)){
                sum += edgeWt;
            }
        }
        return sum;
        
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