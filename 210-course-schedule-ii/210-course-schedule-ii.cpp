class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>visited;
    vector<int>result;
    
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
        result.push_back(i);
        
        return false;
        
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& matrix) {
        
        visited.resize(n,0);
        graph.resize(n);
        
        for(int i=0;i<matrix.size();i++){
            graph[matrix[i][0]].push_back(matrix[i][1]);
        }
        
        for(int i=0;i<n;i++){
            
            if(visited[i]==0){
                
                if(isCycle(i)==true){
                    
                    return {};
                    
                }
                
            }
            
        }
        
        return result;
        
    }
};