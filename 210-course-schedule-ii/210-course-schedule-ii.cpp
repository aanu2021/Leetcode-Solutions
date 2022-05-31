class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& matrix) {
        
        vector<vector<int>>graph(n);
        
        vector<int>indegree(n,0);
        
        for(int i=0;i<matrix.size();i++){
            graph[matrix[i][1]].push_back(matrix[i][0]);
            indegree[matrix[i][0]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            
            if(indegree[i]==0){
                q.push(i);
            }
            
        }
        
        vector<bool>visited(n,false);
        
        vector<int>result;
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            if(visited[node]==true){
                continue;
            }
            
            visited[node]=true;
            
            result.push_back(node);
            
            for(int j:graph[node]){
                
                indegree[j]--;
                
                if(indegree[j]==0){
                    q.push(j);
                }
                
            }
            
        }
        
        if(result.size()==n){
            return result;
        }else{
            return {};
        }
        
    }
};