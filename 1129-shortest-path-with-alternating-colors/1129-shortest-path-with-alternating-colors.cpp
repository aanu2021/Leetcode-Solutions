class Solution {
public:
    
    int bfs_red_blue(int n,vector<vector<pair<int,int>>>&graph,int target){
        
        queue<pair<int,int>>q;
        
        vector<vector<bool>>visited(n,vector<bool>(2,false));
        
        q.push({0,-1});
        
        int lvl=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int node=curr.first;
                int color=curr.second;
                
                if(color!=-1){
                    
                    if(visited[node][color]){
                        continue;
                    }else{
                        visited[node][color]=true;
                    }
                    
                }
                
                if(node==target){
                    return lvl;
                }
                
                for(auto nbr:graph[node]){
                    
                    int v=nbr.first;
                    int edge_col=nbr.second;
                    
                    if(edge_col!=color){
                        
                        if(visited[v][edge_col]==false){
                            
                            q.push({v,edge_col});
                            
                        }
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<redEdges.size();++i){
            
            graph[redEdges[i][0]].push_back({redEdges[i][1],0});
            
        }
        
        for(int i=0;i<blueEdges.size();++i){
            
            graph[blueEdges[i][0]].push_back({blueEdges[i][1],1});
            
        }
        
        vector<int>dist(n);
        
        dist[0]=0;
        
        for(int i=1;i<n;++i){
            
            dist[i]=bfs_red_blue(n,graph,i);
            
        }
        
        return dist;
        
    }
};