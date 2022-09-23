class Solution {
public:
    
    vector<int> bfs_red_blue(int n,vector<vector<pair<int,int>>>&graph){
        
        queue<pair<int,int>>q;
        
        vector<vector<bool>>visited(n,vector<bool>(2,false));
        
        q.push({0,0});   // 0 --> Red Color
        q.push({0,1});  //  1 --> Blue Color
        
        int lvl=0;
        
        vector<int>red_dist(n,1e9);
        
        vector<int>blue_dist(n,1e9);
        
        red_dist[0] = 0;
        
        blue_dist[0] = 0;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int node=curr.first;
                int color=curr.second;
                
                if(visited[node][color]){
                    
                    continue;
                    
                }
                
                visited[node][color] = true;
                
                for(auto nbr:graph[node]){
                    
                    int v=nbr.first;
                    int edge_col=nbr.second;
                    
                    if(color==0){
                        
                        if(edge_col==1 && blue_dist[v] > red_dist[node] + 1){
                            
                            blue_dist[v] = red_dist[node] + 1;
                            
                            q.push({v,1});
                            
                        }
                        
                    }
                    
                    else{
                        
                        if(edge_col==0 && red_dist[v] > blue_dist[node] + 1){
                            
                            red_dist[v] = blue_dist[node] + 1;
                            
                            q.push({v,0});
                            
                        }
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        vector<int>dist(n,1e9);
        
        for(int i=0;i<n;++i){
            
            dist[i] = min(red_dist[i],blue_dist[i]);
            
            if(dist[i]>=1e9){
                
                dist[i] = -1;
                
            }
            
        }
        
        return dist;
        
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<redEdges.size();++i){
            
            graph[redEdges[i][0]].push_back({redEdges[i][1],0});
            
        }
        
        for(int i=0;i<blueEdges.size();++i){
            
            graph[blueEdges[i][0]].push_back({blueEdges[i][1],1});
            
        }
        
        return bfs_red_blue(n,graph);
        
    }
};