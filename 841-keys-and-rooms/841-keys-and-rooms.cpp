class Solution {
public:
    
    void dfs(int u,vector<vector<int>>&graph,vector<bool>&visited){
        
        if(visited[u]) return;
        
        visited[u] = true;
        
        for(int v:graph[u]){
            
            if(visited[v]) continue;
            
            dfs(v,graph,visited);
            
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<bool>visited(n,false);
        
        dfs(0,graph,visited);
        
        for(int i=0;i<n;++i){
            if(!visited[i]){
                return false;
            }
        }
        
        return true;
        
    }
};