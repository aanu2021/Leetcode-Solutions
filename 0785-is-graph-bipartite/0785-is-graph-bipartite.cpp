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
    
    bool isCycle2(int src,vector<vector<int>>&graph,vector<int>&color){
        
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto curr = q.front(); q.pop();
                int u = curr.first;
                int par = curr.second;
                
                for(int v:graph[u]){
                    if(v==par) continue;
                    if(color[v]==-1){
                        color[v] = 1 - color[u];
                        q.push({v,u});
                    }
                    else{
                        if(color[v]==color[u]) return true;
                    }
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
                if(isCycle2(i,graph,color)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};