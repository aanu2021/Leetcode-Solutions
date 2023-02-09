//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<int>disc,low,parent,isAp;
    int timer = 0;
    
    void dfs(int u,vector<int>adj[]){
        disc[u] = low[u] = timer++;
        int child = 0;
        for(int v : adj[u]){
            if(disc[v]==-1){
                child++;
                parent[v] = u;
                dfs(v,adj);
                low[u] = min(low[u],low[v]);
                if(parent[u]==-1 && child >= 2) isAp[u] = true;
                if(parent[u]!=-1 && low[v] >= disc[u]) isAp[u] = true;
            }
            else if(v != parent[u]){
                low[u] = min(low[u],low[v]);
            }
        }
    }
  
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        
        disc.clear();
        low.clear();
        parent.clear();
        isAp.clear();
        
        disc = vector<int>(n,-1);
        low = vector<int>(n,-1);
        parent = vector<int>(n,-1);
        isAp = vector<int>(n,0);
        timer = 0;
        
        dfs(0,adj);
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(isAp[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends