class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int target) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        vector<vector<int>>dist(n,vector<int>(n,10000000));
        
        for(int i=0;i<n;++i){
            
            dist[i][i]=0;
            
        }
        
        for(int i=0;i<edges.size();++i){
            
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
            
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        
        for(int k=0;k<n;++k){
            
            for(int i=0;i<n;++i){
                
                for(int j=0;j<n;++j){
                    
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        
                        dist[i][j] = dist[i][k] + dist[k][j];
                        
                    }
                    
                }
                
            }
            
        }
        
        
        int min_val = 1e9;
        
        int min_node = 0;
        
        for(int i=0;i<n;++i){
            
            int cnt=0;
            
            for(int j=0;j<n;++j){
                
                if(dist[i][j] <= target){
                    
                    cnt++;
                    
                }
                
            }
            
            if(cnt<=min_val){
                
                min_val = cnt;
                
                min_node = i;
                
            }
            
        }
        
        return min_node;
        
    }
};