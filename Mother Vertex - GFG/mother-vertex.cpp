// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    stack<int>st;
    
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int node,vector<vector<int>>&graph,vector<bool>&visited){
        
        if(visited[node]==true){
            return;
        }
        
        visited[node]=true;
        
        for(int j:graph[node]){
            
            if(visited[j]==true){
                continue;
            }
            
            dfs(j,graph,visited);
            
        }
        
        st.push(node);
        
    }
    
	int findMotherVertex(int n, vector<int>adj[])
	{
	    
	    vector<vector<int>>graph(n);
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<adj[i].size();j++){
	            graph[i].push_back(adj[i][j]);
	        }
	    }
	    
	    vector<bool>visited(n,false);
	    
	    for(int i=0;i<n;i++){
	        if(visited[i]==true){
	            continue;
	        }
	        dfs(i,graph,visited);
	    }
	    
	    int node=st.top();
	    
	    for(int i=0;i<n;i++){
	        visited[i]=false;
	    }
	    
	    dfs(node,graph,visited);
	    
	    int flag=node;
	    
	    for(int i=0;i<n;i++){
	        if(visited[i]==false){
	            flag=-1;
	            break;
	        }
	    }
	    
	    return flag;
	    
	}

};

// { Driver Code Starts.
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends