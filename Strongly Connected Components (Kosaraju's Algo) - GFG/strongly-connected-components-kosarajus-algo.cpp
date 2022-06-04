// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	stack<int>st;
	
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
	
	void dfs2(int node,vector<vector<int>>&graph,vector<bool>&visited){
	    
	    if(visited[node]==true){
	        return;
	    }
	    
	    visited[node]=true;
	    
	    for(int j:graph[node]){
	        
	        if(visited[j]==true){
	            continue;
	        }
	        
	        dfs2(j,graph,visited);
	        
	    }
	    
	}
	
    int kosaraju(int n, vector<int> adj[])
    {
        
        vector<bool>visited(n,false);
        
        vector<vector<int>>al(n);
        vector<vector<int>>ral(n);
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<adj[i].size();j++){
                
                al[i].push_back(adj[i][j]);
                ral[adj[i][j]].push_back(i);
                
            }
            
        }
        
        for(int i=0;i<n;i++){
            
            if(visited[i]==true){
                continue;
            }
            
            dfs(i,al,visited);
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        
        while(!st.empty()){
            
            int node=st.top();
            st.pop();
            
            if(visited[node]==true){
                continue;
            }
            
            dfs2(node,ral,visited);
            
            ans++;
            
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends