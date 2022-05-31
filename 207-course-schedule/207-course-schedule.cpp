class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>visited;
    
    bool isCycle(int i){
        
        if(visited[i]==2){
            return true;
        }
        
        visited[i]=2;
        
        for(int j:graph[i]){
            
            if(visited[j]!=1){
                
                if(isCycle(j)==true){
                    
                    return true;
                    
                }
                
            }
            
        }
        
        visited[i]=1;
        
        return false;
        
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        visited.resize(n,0);
        graph.resize(n);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<n;i++){
            
            if(visited[i]==0){
                
                if(isCycle(i)==true){
                    return false;
                }
                
            }
            
        }
        
        return true;
        
    }
};