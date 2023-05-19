class Solution {
public:
    
    bool isCycle(int u,vector<vector<int>>&graph,vector<int>&color){
        
        for(int v:graph[u]){
            if(color[v]==-1){
                color[v] = 1 - color[u];
                bool flag = isCycle(v,graph,color);
                if(flag) return true;
            }
            else{
                if(color[v]==color[u]){
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 1;
                if(isCycle(i,graph,color)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};