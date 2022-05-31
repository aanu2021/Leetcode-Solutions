// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    bool possible=false;
    
    
    void func(vector<vector<int>>&graph,int src,vector<bool>&visited,vector<int>&solution){
        
        if(visited[src]==true || possible==true){
            return;
        }
        
        visited[src]=true;
        
        if(solution.size()==visited.size()){
            
            possible=true;
            
            visited[src]=false;
            
            return;
            
        }
        
        
        for(int j:graph[src]){
            
            if(visited[j]==false){
                
                solution.push_back(j);
                
                func(graph,j,visited,solution);
                
                solution.pop_back();
                
            }
            
        }
        
        visited[src]=false;
        
    }
    
    bool check(int n,int m,vector<vector<int>> edges)
    {
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            u--;
            v--;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        
        
        for(int i=0;i<n;i++){
            
            vector<int>solution;
            
            vector<bool>visited(n,false);
            
            solution.push_back(i);
            
            func(graph,i,visited,solution);
            
        }
        
        return possible;
        
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends