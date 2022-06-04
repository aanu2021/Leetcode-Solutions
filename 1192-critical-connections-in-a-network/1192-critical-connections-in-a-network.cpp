class Solution {
public:
    
    int timer=0;
    
    vector<vector<int>>bridges;
    
    vector<vector<int>>graph;
    vector<int>disc;
    vector<int>low;
    vector<int>parent;
   
    
    void dfs(int u){
        
        disc[u]=low[u]=timer++;
        
        for(int v:graph[u]){
            
            if(disc[v]==-1){
                
                parent[v]=u;
                
                dfs(v);
                
                low[u]=min(low[u],low[v]);
                
                if(low[v]>disc[u]){
                    
                    bridges.push_back({u,v});
                    
                }
                
            }
            
            else if(v!=parent[u]){
                
                low[u]=min(low[u],disc[v]);
                
            }
            
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        
        graph.resize(n);
        disc.resize(n,-1);
        low.resize(n,-1);
        parent.resize(n,-1);
      
        
        for(int i=0;i<c.size();i++){
            
            graph[c[i][0]].push_back(c[i][1]);
            graph[c[i][1]].push_back(c[i][0]);
            
        }
        
        
        dfs(0);
        
        return bridges;
        
    }
};