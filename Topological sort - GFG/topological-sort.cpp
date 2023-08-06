//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	bool isCycle(int u,vector<int>graph[],vector<int>&visited,vector<int>&topo){
	    if(visited[u] == 2) return true;
	    visited[u] = 2;
	    for(int v:graph[u]){
	        if(visited[v]==2){
	            return true;
	        }
	        else if(visited[v]==0){
	            bool flag = isCycle(v,graph,visited,topo);
	            if(flag) return true;
	        }
	    }
	    visited[u] = 1;
	    topo.push_back(u);
	    return false;
	}
	
	vector<int> topoSort(int n, vector<int> graph[]) 
	{
	    vector<int>visited(n,0);
	    vector<int>answer;
	    for(int i=0;i<n;i++){
	        if(visited[i]) continue;
	        vector<int>topo;
	        if(isCycle(i,graph,visited,topo)){
	            return {};
	        }
	        else{
	           // reverse(topo.begin(),topo.end());
	            for(int &ele : topo){
	                answer.push_back(ele);
	            }
	        }
	    }
	    reverse(answer.begin(),answer.end());
	    return answer;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends