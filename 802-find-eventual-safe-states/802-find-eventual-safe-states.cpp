class Solution {
public:
    
    bool dfs(int u,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&curr_visited,vector<bool>&check){
        
        visited[u]=true;
        curr_visited[u]=true;
        
        for(int v:graph[u]){
            
            if(curr_visited[v]){
                return true;
            }
            
            else if(visited[v]==false && dfs(v,graph,visited,curr_visited,check)){
                
                return true;
                
            }
            
        }
        
        curr_visited[u]=false;
        
        check[u]=true;
        
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<bool>visited(n,false);
        
        vector<bool>curr_vis(n,false);
        
        vector<bool>check(n,false);
        
        
        for(int i=0;i<n;++i){
            
            if(visited[i]==false){
                
                dfs(i,graph,visited,curr_vis,check);
                
            }
            
        }
        
        vector<int>safe_nodes;
        
        for(int i=0;i<n;++i){
            
            if(check[i]){
                
                safe_nodes.push_back(i);
                
            }
            
        }
        
        return safe_nodes;
        
    }
};