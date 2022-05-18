class Solution {
public:
    
    vector<vector<int>>graph;
    
    vector<vector<int>>bridges;
    
    int time=0;
    
    void dfs(int u,vector<int>&parent,vector<int>&disc,vector<int>&low){
        
        disc[u]=low[u]=time++;
        
        for(int v:graph[u]){
            
            if(disc[v]==-1){
                
                parent[v]=u;
                
                dfs(v,parent,disc,low);
                
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
        
        for(int i=0;i<c.size();i++){
            graph[c[i][0]].push_back(c[i][1]);
            graph[c[i][1]].push_back(c[i][0]);
        }
        
        vector<int>parent(n,-1);
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        
        dfs(0,parent,disc,low);
        
        return bridges;
        
    }
};