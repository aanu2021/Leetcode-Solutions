class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int>safe_vis(n,false);
        
        vector<int>indegree(n,0);
        
        vector<vector<int>>rgraph(n);
        
        for(int i=0;i<n;++i){
            
            for(int j:graph[i]){
                
                indegree[i]++;
                
                rgraph[j].push_back(i);
                
            }
            
        }
        
        queue<int>q;
        
        for(int i=0;i<n;++i){
            
            if(indegree[i]==0){
                
                q.push(i);
                
            }
            
        }
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int node=q.front();
                q.pop();
                
                safe_vis[node]=true;
                
                for(int v:rgraph[node]){
                    
                    indegree[v]--;
                    
                    if(indegree[v]==0){
                        
                        q.push(v);
                        
                    }
                    
                }
                
            }
            
        }
        
        vector<int>safe_nodes;
        
        for(int i=0;i<n;++i){
            
            if(safe_vis[i]){
                
                safe_nodes.push_back(i);
                
            }
            
        }
        
        return safe_nodes;
        
    }
};