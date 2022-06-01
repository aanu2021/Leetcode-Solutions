class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        
        vector<int>indegree(n,0);
        
        for(int i=0;i<edges.size();i++){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            
        }
        
        vector<int>height(n,0);
        
        int level=0;
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        
        vector<bool>visited(n,false);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int node=q.front();
                q.pop();

                if(visited[node]==true){
                    continue;
                }

                visited[node]=true;

                height[node]=level;
                
                for(int j:graph[node]){
                    
                    indegree[j]--;
                    
                    if(indegree[j]==1){
                        q.push(j);
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        int maxi=*max_element(height.begin(),height.end());
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(height[i]==maxi){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};