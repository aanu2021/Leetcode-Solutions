class Solution {
public:
    
    int dfs(int node,int parent,vector<vector<pair<int,int>>>&graph){
        
        int total = 0;
        
        for(auto nbrs:graph[node]){
            
            int nbr = nbrs.first;
            int edge_wt = nbrs.second;
            
            if(nbr==parent) continue;
            
            total+=edge_wt;
            
            total+=dfs(nbr,node,graph);
            
        }
        
        return total;
        
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<c.size();++i){
            graph[c[i][0]].push_back({c[i][1],0});
            graph[c[i][1]].push_back({c[i][0],1});
        }
        
        int not_ans=dfs(0,-1,graph);
        
        return (n-1-not_ans);
        
    }
};