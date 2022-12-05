//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int u,vector<int>adj[],vector<int>&col){
        
        for(int v:adj[u]){
            if(col[v]==col[u]) return false;
            if(col[v]==-1){
                col[v] = 1 - col[u];
                bool flag = dfs(v,adj,col);
                if(!flag) return false;
            }
        }
        return true;
        
    }

	bool isBipartite(int n, vector<int>adj[]){
	    
	    vector<int>color(n,-1);
	    
	    for(int i=0;i<n;i++){
	        if(color[i]!=-1) continue;
	        color[i] = 1;
	        if(dfs(i,adj,color)==false){
	            return false;
	        }
	    }
	    
	    return true;
	    
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends