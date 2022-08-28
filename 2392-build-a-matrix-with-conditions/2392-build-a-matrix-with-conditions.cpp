class Solution {
public:
    
    vector<int>topo_sort(int k,vector<vector<int>>&edges){
        
        vector<vector<int>>graph(k+1);
        
        vector<int>indegree(k+1,0);
        
        vector<int>path;
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][1]].push_back(edges[i][0]);
            
            indegree[edges[i][0]]++;
            
        }
        
        queue<int>q;
        
        for(int i=1;i<=k;++i){
            
            if(indegree[i]==0){
                
                q.push(i);
                
            }
            
        }
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int node=q.front();
                q.pop();
                
                path.push_back(node);
                
                for(int v:graph[node]){
                    
                    indegree[v]--;
                    
                    if(indegree[v]==0){
                        q.push(v);
                    }
                    
                }
                
            }
            
        }
        
        reverse(path.begin(),path.end());
        
        if(path.size()!=k){
            return {};
        }
        
        else{
            return path;
        }
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row=topo_sort(k,rowConditions);
        
        vector<int>col=topo_sort(k,colConditions);
        
        if(row.size()==0 || col.size()==0){
            return {};
        }
        
        vector<int>index_row(k+1,-1);
        vector<int>index_col(k+1,-1);
        
        for(int i=0;i<k;++i){
            
            index_row[row[i]]=i;
            index_col[col[i]]=i;
            
        }
        
        vector<vector<int>>arr(k,vector<int>(k,0));
        
        for(int i=1;i<=k;++i){
            
            arr[index_row[i]][index_col[i]]=i;
            
        }
        
        return arr;
        
    }
};