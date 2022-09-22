class Solution {
public:
    
    vector<int>topo_sort(int k,vector<vector<int>>&edges){
        
        vector<vector<int>>graph(k+1);
        
        vector<int>indegree(k+1,0);
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            
            indegree[edges[i][1]]++;
            
        }
        
        vector<int>ans;
        
        queue<int>q;
        
        for(int i=1;i<=k;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int nbr:graph[node]){
                
                indegree[nbr]--;
                
                if(indegree[nbr]==0){
                    
                    q.push(nbr);
                    
                }
                
            }
            
        }
        
        if(ans.size()!=k){
            
            return {};
            
        }
        
        return ans;
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row_topo=topo_sort(k,rowConditions);
        
        vector<int>col_topo=topo_sort(k,colConditions);
        
        if(row_topo.size()==0 || col_topo.size()==0){
            
            return {};
            
        }
        
        vector<int>index_row(k+1,-1);
        vector<int>index_col(k+1,-1);
        
        for(int i=0;i<row_topo.size();++i){
            
            index_row[row_topo[i]] = i;
            
        }
        
        for(int i=0;i<col_topo.size();++i){
            
            index_col[col_topo[i]] = i;
            
        }
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        
        for(int i=1;i<=k;++i){
            
            ans[index_row[i]][index_col[i]] = i;
            
        }
        
        return ans;
        
    }
};