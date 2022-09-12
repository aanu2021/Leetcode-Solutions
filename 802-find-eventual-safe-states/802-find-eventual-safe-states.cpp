class Solution {
public:
    
    bool dfs(int u,vector<vector<int>>&graph,
          vector<bool>&visited,vector<bool>&curr_vis,vector<bool>&check){
        
      visited[u]=true;
        
      curr_vis[u]=true;
        
        for(int v:graph[u]){
            
            if(curr_vis[v]){
                
                return true;
                
            }
            
            if(visited[v]==false && dfs(v,graph,visited,curr_vis,check)){
                
                return true;
                
            }
            
        }
        
        curr_vis[u]=false;
        
        check[u]=true;
        
        return false;
        
 }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<bool>visited(n,false);
        
        vector<bool>curr_vis(n,false);
        
        vector<bool>check(n,false);
        
        vector<int>safe_nodes;
        
        for(int i=0;i<n;++i){
            
            if(visited[i]==false){
                
                dfs(i,graph,visited,curr_vis,check);
                
            }
            
        }
        
        
        for(int i=0;i<n;++i){
            
            if(check[i]){
                
                safe_nodes.push_back(i);
                
            }
            
        }
        
        return safe_nodes;
        
    }
};